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