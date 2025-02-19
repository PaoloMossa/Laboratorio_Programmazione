//
// Created by Paolo Mossa on 19/02/25.
//

#ifndef ATTIVITASEMPLICE_H
#define ATTIVITASEMPLICE_H
#include <iostream>

#include "Attivita.h"


class AttivitaSemplice : public Attivita {
public:
    AttivitaSemplice(const std::string& descrizione, bool completata = false)
        : Attivita(descrizione, completata) {}

    void stampa() const override;

    std::string serializza() const override;

    //Factory Method statico per creare da riga serializzata
    static AttivitaSemplice* creaDaSerializzazione(const std::string& riga) {
        size_t pos1 = riga.find(';');
        size_t pos2 = riga.find(';', pos1 + 1);
        if (pos1 == std::string::npos || pos2 == std::string::npos) {
            return nullptr; // Formato non valido
        }
        std::string descrizione = riga.substr(pos1 + 1, pos2 - pos1 - 1);
        bool completata = (riga[pos2 + 1] == '1');
        return new AttivitaSemplice(descrizione, completata);
    }
};



#endif //ATTIVITASEMPLICE_H
