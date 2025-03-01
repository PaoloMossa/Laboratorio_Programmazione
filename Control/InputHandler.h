//
// Created by Paolo Mossa on 20/02/25.
//

#ifndef CLICKHANDLER_H
#define CLICKHANDLER_H
#include "../Domain/ListaAttivita.h"
#include "TipoInput.h"


class InputHandler {
private:
    ListaAttivita &listaAttivita;

    void nuovaAttivita();

    int getIndiceDaTastiera(std::string &testoDaVisualizzare);

    std::optional<int> stringToInt(const std::string &str);

    void modificaAttivita();

    void rimuoviAttivita();

    void completaAttivita();

    bool isValidIndex(int indice);
public:
    InputHandler(ListaAttivita &listaAttivita) : listaAttivita(listaAttivita) {}



    void handleInput(TipoInput input);

};


#endif //CLICKHANDLER_H
