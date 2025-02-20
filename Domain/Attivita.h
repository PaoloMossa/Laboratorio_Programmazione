//
// Created by Paolo Mossa on 19/02/25.
//

#ifndef ATTIVITA_H
#define ATTIVITA_H
#include <string>


//Abstract class for a generic activity
class Attivita {
protected:
    std::string descrizione;
    bool completata;
public:

    explicit Attivita(const std::string& descrizione, bool completata = false) : descrizione(descrizione), completata(completata) {}


    virtual void stampa() const = 0; // Print details
    virtual std::string serializza() const = 0; // For saving to file
    virtual std::unique_ptr<Attivita> creaDaSerializzazione(const std::string &riga) = 0; // For loading from file

    //Getter methods

    virtual std::string getType() const = 0;

    std::string getDescrizione() const {
        return descrizione;
    }

    bool isCompletata() const {
        return completata;
    }

    //Setter method
    void setCompletata(bool stato) {
        completata = stato;
    }
    void setDescrizione(const std::string& nuovaDescrizione) {
        descrizione = nuovaDescrizione;
    }

    virtual ~Attivita() = default; // Virtual destructor
};



#endif //ATTIVITA_H
