//
// Created by Paolo Mossa on 20/02/25.
//

#ifndef TIPOINPUT_H
#define TIPOINPUT_H
#include <string>


enum class TipoInput {
    Nuovo,
    Modifica,
    Rimuovi,
    Esci,
    Non_valido
};

//Function for converting string to TipoInput
TipoInput stringToTipoInput(const std::string &input);

#endif //TIPOINPUT_H
