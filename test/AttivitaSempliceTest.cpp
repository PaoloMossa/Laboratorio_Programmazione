//
// Created by Paolo Mossa on 01/03/25.
//
#include "gtest/gtest.h"
#include "../Domain/Attivita.h"
#include "../Domain/AttivitaSemplice.h"


TEST(AttivitaSempliceTest,TestCreaDaSerializzazione) {
    std::string riga = "Semplice;Descrizione di prova;0";
    AttivitaSemplice attivita("");
    auto attivitaSerializzata = attivita.creaDaSerializzazione(riga);

    ASSERT_TRUE(attivitaSerializzata);
    ASSERT_EQ(attivitaSerializzata->getType(),"Semplice");
    ASSERT_EQ("Descrizione di prova", attivitaSerializzata->getDescrizione());
    ASSERT_FALSE(attivitaSerializzata->isCompletata());
}

TEST(AttivitaSemplice,TestCreaDaSerializzazione_FormatoNonValido) {
    std::string riga = "Semplice;Descrizione;Sbagliata;0";
    AttivitaSemplice attivita("");
    auto attivitaSerializzata = attivita.creaDaSerializzazione(riga);

    ASSERT_EQ(attivitaSerializzata,nullptr);
}

TEST(AttivitaSemplice,TestSerializza_completata) {
    AttivitaSemplice attivita("Attivita di prova", true);
    std::string serializzato = attivita.serializza();

    ASSERT_EQ(serializzato, "Semplice;Attivita di prova;1");
}

TEST(AttivitaSemplice,TestSerializza_nonCompletata) {
    AttivitaSemplice attivita("Attivita di prova", false);
    std::string serializzato = attivita.serializza();

    ASSERT_EQ(serializzato, "Semplice;Attivita di prova;0");
}