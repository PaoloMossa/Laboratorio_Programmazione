//
// Created by Paolo Mossa on 19/02/25.
//

#include "GestoreFile.h"
//#include "../domain/AttivitaImportante.h"
#include <fstream>

#include "../domain/AttivitaSemplice.h"

Attivita* GestoreFile::getAttivitaDaRiga(const std::string& riga, const std::string& type) const {
    if (type == "Semplice") {
        return AttivitaSemplice::creaDaSerializzazione(riga);
    } else if (type == "Importante") {
//        return AttivitaImportante::creaDaSerializzazione(riga);
    }
    return nullptr;
}

std::list<Attivita*> GestoreFile::caricaDaFile() const {
    std::list<Attivita*> attivitaList;
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore nell'apertura del file per il caricamento." << std::endl;
        return attivitaList;
    }

    std::string riga;
    while (std::getline(file, riga)) {
        size_t pos = riga.find(';');
        if (pos == std::string::npos) {
            std::cerr << "Riga non valida: " << riga << std::endl;
            continue;
        }
        std::string tipo = riga.substr(0, pos);
        Attivita* attivita = getAttivitaDaRiga(riga, tipo);
        if (attivita) {
            attivitaList.push_back(attivita);
        } else {
            std::cerr << "Errore nella deserializzazione di un'attività." << std::endl;
        }
    }
    file.close();
    return attivitaList;
}