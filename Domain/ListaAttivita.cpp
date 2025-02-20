//
// Created by Paolo Mossa on 19/02/25.
//

#include "ListaAttivita.h"

#include <iostream>
#include <ostream>

void ListaAttivita::addAttivita(std::unique_ptr<Attivita> attivita) {
    attivitaList.push_back(std::move(attivita));
}