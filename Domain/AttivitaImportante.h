//
// Created by Paolo Mossa on 20/02/25.
//

#ifndef ATTIVITAIMPORTANTE_H
#define ATTIVITAIMPORTANTE_H
#include "Attivita.h"


class AttivitaImportante : public Attivita {
public:
    explicit AttivitaImportante(const std::string& descrizione, bool completata = false)
        : Attivita(descrizione, completata) {}

    void stampa() const override;

    std::string serializza() const override;

    std::string getType() const override;

    //Factory Method statico per creare l'attività da riga serializzata
    std::unique_ptr<Attivita> creaDaSerializzazione(const std::string &riga) override;
};



#endif //ATTIVITAIMPORTANTE_H
