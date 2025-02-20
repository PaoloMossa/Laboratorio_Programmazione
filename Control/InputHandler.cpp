//
// Created by Paolo Mossa on 20/02/25.
//

#include "InputHandler.h"
#include "TipoInput.h"

void InputHandler::handleInput(TipoInput input) {
    switch(input) {
        case TipoInput::Nuovo:
            std::cout << "nuovo" << std::endl;
            break;
        case TipoInput::Modifica:
            std::cout << "modifica" << std::endl;
            break;
        case TipoInput::Rimuovi:
            std::cout << "rimuovi" << std::endl;
            break;
        case TipoInput::Esci:
            std::cout << "esci" << std::endl;
            break;
        case TipoInput::Non_valido:
            std::cout << "non valido" << std::endl;
            break;
        default:
            std::cout << "default";
    }
}
