//
// Created by Paolo Mossa on 20/02/25.
//

#include "InputHandler.h"
#include "TipoInput.h"
#include "../Domain/AttivitaImportante.h"
#include "../Domain/AttivitaSemplice.h"

void InputHandler::modificaAttivita() {
    std::string indice;
    std::cout << "Inserire l'indice dell'attività che si vuole modificare: ";
    std::cin >> indice;
    std::optional<int> indiceOpt = stringToInt(indice);
    if (!indiceOpt.has_value()) {
        std::cerr << "Errore durante la conversione." << std::endl;
        return;
    }
    int indiceInt = indiceOpt.value();
    if (isValidIbdex(indiceInt))
        listaAttivita.modificaAttivita(indiceInt);
}

bool InputHandler::isValidIbdex(int indice) {
    if (indice < 0) {
        std::cerr << "Error: Index cannot be negative." << std::endl;
        return false;
    }
    if (indice >= listaAttivita.size()) {
        std::cerr << "Error: Index is out of bounds. Must be less than " << listaAttivita.size() << "." << std::endl;
        return false;
    }
    return true;
}

void InputHandler::handleInput(TipoInput input) {
    switch(input) {
        case TipoInput::Nuovo:
            std::cout << "nuovo" << std::endl;
            nuovaAttivita();
            break;
        case TipoInput::Modifica:
            std::cout << "modifica" << std::endl;

            modificaAttivita();

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

//FIXME The following method could be implemented in a Factoy Mehod object
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

std::optional<int> InputHandler::stringToInt(const std::string& str) {
    try {
        size_t pos; // To check if the *entire* string was converted
        int result = std::stoi(str, &pos); // Convert string to int
        if (pos != str.length()) {
            // If not the entire string was consumed, it's an error
            return std::nullopt; // Indicate conversion failure
        }
        return result;
    } catch (const std::invalid_argument&) {
        // String cannot be converted to an integer
        return std::nullopt; // Indicate conversion failure
    } catch (const std::out_of_range&) {
        // Integer is out of range for int
        return std::nullopt; // Indicate conversion failure
    }
}
