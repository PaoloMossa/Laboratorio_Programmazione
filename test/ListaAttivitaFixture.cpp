//
// Created by Paolo Mossa on 23/02/25.
//
#include "../Domain/AttivitaImportante.h"
#include "../Domain/AttivitaSemplice.h"
#include "gtest/gtest.h"
#include "../Domain/ListaAttivita.h"

class ListaAttivitaSuite : public ::testing::Test {
protected:
    virtual void SetUp() {
        auto first = std::make_unique<AttivitaSemplice>(AttivitaSemplice("Esempio di attività semplice"));
        auto second = std::make_unique<AttivitaImportante>(AttivitaImportante("Esempio di attività importante"));
        listaAttivita.addAttivita(std::move(first));
        listaAttivita.addAttivita(std::move(second));
    }
    ListaAttivita listaAttivita;
};

TEST_F(ListaAttivitaSuite,TestConsistenzaVettore) {
    ASSERT_EQ(2, listaAttivita.size());

    listaAttivita.eliminaAttivita(0);

    ASSERT_EQ(1,listaAttivita.size());
}