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
    GestoreFile &gestoreFile;

    void nuovaAttivita();

    int getIndiceDaTastiera(std::string &testoDaVisualizzare);

    std::optional<int> stringToInt(const std::string &str);

    void modificaAttivita();

    void rimuoviAttivita();

    void completaAttivita();

    bool isValidIndex(int indice);
public:
    InputHandler(ListaAttivita &listaAttivita, GestoreFile &gestoreFile) : listaAttivita(listaAttivita), gestoreFile(gestoreFile) {}



    void handleInput(TipoInput input);

};


#endif //CLICKHANDLER_H
