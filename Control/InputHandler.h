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

    std::optional<int> stringToInt(const std::string &str);

    void modificaAttivita();
    bool isValidIbdex(int indice);
public:
    InputHandler(ListaAttivita &listaAttivita, GestoreFile &gestoreFile) : listaAttivita(listaAttivita), gestoreFile(gestoreFile) {}



    void handleInput(TipoInput input);

};


#endif //CLICKHANDLER_H
