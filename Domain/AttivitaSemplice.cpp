//
// Created by Paolo Mossa on 19/02/25.
//

#include "AttivitaSemplice.h"

void AttivitaSemplice::stampa() const {
    std::cout << (completata ? "[X] " : "[ ] ") << descrizione;
}
std::string AttivitaSemplice::serializza() const  {
    return "Semplice;" + descrizione + ";" + (completata ? "1" : "0");
}

std::string AttivitaSemplice::getType() const {
    return "Semplice";
}

std::unique_ptr<Attivita> AttivitaSemplice::creaDaSerializzazione(const std::string &riga) {
    size_t pos1 = riga.find(';');
    size_t pos2 = riga.find(';', pos1 + 1);
    if (pos1 == std::string::npos || pos2 == std::string::npos) {
        return nullptr; // Formato non valido
    }
    std::string descrizione = riga.substr(pos1 + 1, pos2 - pos1 - 1);
    bool completata = (riga[pos2 + 1] == '1');
    AttivitaSemplice a = AttivitaSemplice(descrizione, completata);
    std::unique_ptr<Attivita> ptr = std::make_unique<AttivitaSemplice>(a);
    return std::move(ptr);

}
