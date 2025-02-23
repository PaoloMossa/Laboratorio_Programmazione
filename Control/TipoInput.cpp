//
// Created by Paolo Mossa on 20/02/25.
//

#include "TipoInput.h"
#include <cctype> // For toupper if case-insensitive needed

TipoInput stringToTipoInput(const std::string &input) {
    std::string upperInput = input;
    for (char &c : upperInput) {
        c = std::toupper(c);
    }
    if (upperInput == "NUOVO") {
        return TipoInput::Nuovo;
    } else if (upperInput == "MODIFICA") {
        return TipoInput::Modifica;
    } else if (upperInput == "RIMUOVI") {
        return TipoInput::Rimuovi;
    } else if (upperInput == "ESCI") {
        return TipoInput::Esci;
    }
    else if (upperInput == "COMPLETA") {
        return TipoInput::Completa;
    } else {
        return TipoInput::Non_valido;
    }
}
