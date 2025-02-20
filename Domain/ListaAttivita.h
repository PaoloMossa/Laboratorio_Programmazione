//
// Created by Paolo Mossa on 19/02/25.
//

#ifndef LISTAATTIVITA_H
#define LISTAATTIVITA_H

#include <iostream>
#include <list>
#include <ostream>

#include "Attivita.h"
#include "../Persistence/GestoreFile.h"

class GestoreFile;

class ListaAttivita {
private:
    std::vector<std::unique_ptr<Attivita>> attivitaList;
public:
    explicit ListaAttivita() = default;

    void addAttivita(std::unique_ptr<Attivita> attivita);

    void stampa() const {
        for (const auto& attivita : attivitaList) {
            attivita->stampa();
            std::cout << std::endl;
        }
    }

    std::vector<std::unique_ptr<Attivita>> getListaAttivita() {
        return std::move(attivitaList);
    }
};


#endif //LISTAATTIVITA_H
