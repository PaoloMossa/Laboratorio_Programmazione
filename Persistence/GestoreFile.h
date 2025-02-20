//
// Created by Paolo Mossa on 19/02/25.
//

#ifndef GESTOREFILE_H
#define GESTOREFILE_H
#include <list>
#include <string>

#include "../Domain/ListaAttivita.h"

class ListaAttivita;

class GestoreFile {
private:
    const std::string nomeFile;

    std::unique_ptr<Attivita> getAttivitaDaRiga(const std::string &riga, const std::string &type) const;
public:

    GestoreFile(const std::string& nomeFile) : nomeFile(nomeFile) {}

    std::vector<std::unique_ptr<Attivita>> caricaDaFile() const;

    bool salvaSuFile(const std::vector<std::unique_ptr<Attivita>> &attivitaList) const;
};



#endif //GESTOREFILE_H
