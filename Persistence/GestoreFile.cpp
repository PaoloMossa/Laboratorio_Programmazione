//
// Created by Paolo Mossa on 19/02/25.
//

#include "GestoreFile.h"
#include "../Domain/AttivitaImportante.h"
#include <fstream>

#include "../Domain/AttivitaSemplice.h"

std::unique_ptr<Attivita> GestoreFile::getAttivitaDaRiga(const std::string &riga, const std::string &type) const {
    std::unique_ptr<Attivita> attivita;
    if (type == "Semplice") {
        attivita = std::make_unique<AttivitaSemplice>("", false);
    }
    else if (type == "Importante") {
        attivita = std::make_unique<AttivitaImportante>("", false);
    }
    else {
        std::cerr << "Tipo di attività non riconosciuto: " << type << std::endl;
        return nullptr;
    }
    auto result = attivita->creaDaSerializzazione(riga);
    return std::move(result);
}

std::vector<std::unique_ptr<Attivita>> GestoreFile::caricaDaFile() const {
    auto attivitaList = std::make_unique<ListaAttivita>();

    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore nell'apertura del file per il caricamento." << std::endl;
        return attivitaList->getListaAttivita();
    }

    std::string riga;
    while (std::getline(file, riga)) {
        size_t pos = riga.find(';');
        if (pos == std::string::npos) {
            std::cerr << "Riga non valida: " << riga << std::endl;
            continue;
        }
        std::string tipo = riga.substr(0, pos);
        std::unique_ptr<Attivita> attivita = getAttivitaDaRiga(riga, tipo);
        if (attivita) {
            attivitaList->addAttivita(std::move(attivita));
        } else {
            std::cerr << "Errore nella deserializzazione di un'attività." << std::endl;
        }
    }
    file.close();
    return attivitaList->getListaAttivita();
}

bool GestoreFile::salvaSuFile(const std::vector<std::unique_ptr<Attivita>> &attivitaList) const {
    std::ofstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore nell'apertura del file per il salvataggio." << std::endl;
        return false;
    }
    for (const auto& attivita : attivitaList) {
        file << attivita->serializza() << std::endl;
    }
    file.close();
    return true;
}