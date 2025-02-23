//
// Created by Paolo Mossa on 20/02/25.
//

#include "InputHandler.h"
#include "TipoInput.h"
#include "../Domain/AttivitaImportante.h"
#include "../Domain/AttivitaSemplice.h"

void InputHandler::handleInput(TipoInput input) {
    switch(input) {
        case TipoInput::Nuovo:
            std::cout << "nuovo" << std::endl;
            nuovaAttivita();
            break;
        case TipoInput::Modifica:
            std::cout << "modifica" << std::endl;
            break;
        case TipoInput::Rimuovi:
            std::cout << "rimuovi" << std::endl;
            break;
        case TipoInput::Esci:
            std::cout << "inserire exit" << std::endl;
            break;
        case TipoInput::Non_valido:
            std::cout << "non valido" << std::endl;
            break;
        default:
            std::cout << "default";
    }
}

void InputHandler::nuovaAttivita() {
    std::string input;
    std::cout << "inserire tipo di attività (Semplice o Importante): ";
    std::cin >> input;
    std::string upperInput = input;
    for (char &c : upperInput) {
        c = std::toupper(c);
    }
    std::unique_ptr<Attivita> nuovaAttivita;
    if (upperInput == "SEMPLICE")
        nuovaAttivita = std::make_unique<AttivitaSemplice>(AttivitaSemplice(""));
    else if (upperInput == "IMPORTANTE")
        nuovaAttivita = std::make_unique<AttivitaImportante>(AttivitaImportante(""));
    else
        std::cout << "errore durante creazione dell'attività: tipo non valido" << std::endl;

    std::cout << "Inserire descrizione: ";
    std::cin.ignore(); //This prevent getline() getting \n from input, remaining from previous cin.
    std::getline(std::cin, input);
    nuovaAttivita->setDescrizione(input);
    listaAttivita.addAttivita(std::move(nuovaAttivita));
}
