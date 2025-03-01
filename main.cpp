#include <iostream>

#include "Control/InputHandler.h"
#include "Domain/Attivita.h"
#include "Domain/AttivitaSemplice.h"
#include "Domain/ListaAttivita.h"
#include "Control/TipoInput.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    /*
    AttivitaSemplice a = AttivitaSemplice("Fare la spesa", false);
    auto test = std::make_unique<AttivitaSemplice>(a);

    std::unique_ptr<Attivita> b = a.creaDaSerializzazione("prova;Fare la spesa;0");
    ListaAttivita lista;
    lista.addAttivita(std::move(b));
    lista.addAttivita(std::move(test));
    lista.stampa();
    a.stampa();
*/

    std::cout << std::endl << "Prova GestoreFile" << std::endl;
    GestoreFile gestore("prova.txt");

    auto listaCaricata = gestore.caricaDaFile();
    ListaAttivita prova;
    for (auto& attivita : listaCaricata) {
        prova.addAttivita(std::move(attivita));
    }
    prova.stampa();

    std::cout << std::endl << "Prova ClickHandler" << std::endl;

    InputHandler handler(prova);
    while (true) {

        std::cout << std::endl << "LISTA ATTIVITÀ:" << std::endl;
        prova.stampa();
        std::cout << std::endl;

        std::string input;
        std::cout << "Inserire comando: ";
        std::cin >> input;
        if (input == "exit") {
            break;
        }
        TipoInput convertedInput = stringToTipoInput(input);
        handler.handleInput(convertedInput);
    }

    std::cout << "Salvare le modifiche? (y/n)" << std::endl;
    std::string risposta;
    std::cin >> risposta;
    if (risposta != "n")
        gestore.salvaSuFile(prova.getListaAttivita());

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.