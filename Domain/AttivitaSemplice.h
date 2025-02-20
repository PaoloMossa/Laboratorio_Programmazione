//
// Created by Paolo Mossa on 19/02/25.
//

#ifndef ATTIVITASEMPLICE_H
#define ATTIVITASEMPLICE_H
#include <iostream>

#include "Attivita.h"


class AttivitaSemplice : public Attivita {
public:
    explicit AttivitaSemplice(const std::string& descrizione, bool completata = false)
        : Attivita(descrizione, completata) {}

    void stampa() const override;

    std::string serializza() const override;

    std::string getType() const override;

    //Factory Method statico per creare l'attività da riga serializzata
    std::unique_ptr<Attivita> creaDaSerializzazione(const std::string &riga) override;
};



#endif //ATTIVITASEMPLICE_H
