//
// Created by Paolo Mossa on 19/02/25.
//

#ifndef GESTOREFILE_H
#define GESTOREFILE_H
#include <list>
#include <string>


class Attivita;

class GestoreFile {
private:
    const std::string nomeFile;
    Attivita* getAttivitaDaRiga(const std::string& riga, const std::string& type) const;
public:

    GestoreFile(const std::string& nomeFile) : nomeFile(nomeFile) {}

    std::list<Attivita*> caricaDaFile() const;
};



#endif //GESTOREFILE_H
