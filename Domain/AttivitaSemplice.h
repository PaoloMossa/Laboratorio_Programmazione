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

    std::string getType() const override;

    //Factory Method statico per creare da riga serializzata
    static AttivitaSemplice* creaDaSerializzazione(const std::string& riga);
};



#endif //ATTIVITASEMPLICE_H
