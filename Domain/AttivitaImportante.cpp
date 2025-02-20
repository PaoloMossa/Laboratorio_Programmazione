//
// Created by Paolo Mossa on 20/02/25.
//

#include "AttivitaImportante.h"

#include <iostream>

//FIXME find a better way to print colored text, so that it is not dependent on the os
void AttivitaImportante::stampa() const {
    std::cout << (completata ? "[X] " : "[ ] ") << "\033[32m" << descrizione << "\033[0m" << std::endl;
}

std::string AttivitaImportante::serializza() const {
    return "Importante;" + descrizione + ";" + (completata ? "1" : "0");
}

std::string AttivitaImportante::getType() const {
    return "Importante";
}

std::unique_ptr<Attivita> AttivitaImportante::creaDaSerializzazione(const std::string &riga) {
    size_t pos1 = riga.find(';');
    size_t pos2 = riga.find(';', pos1 + 1);
    if (pos1 == std::string::npos || pos2 == std::string::npos) {
        return nullptr; // Formato non valido
    }
    std::string descrizione = riga.substr(pos1 + 1, pos2 - pos1 - 1);
    bool completata = (riga[pos2 + 1] == '1');
    AttivitaImportante a = AttivitaImportante(descrizione, completata);
    std::unique_ptr<Attivita> ptr = std::make_unique<AttivitaImportante>(a);
    return std::move(ptr);
}
