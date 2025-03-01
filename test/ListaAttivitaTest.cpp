//
// Created by Paolo Mossa on 23/02/25.
//
#include "../Domain/AttivitaSemplice.h"
#include "../Domain/AttivitaImportante.h"
#include "../Domain/ListaAttivita.h"
#include "../Persistence/GestoreFile.h"
#include "../Control/InputHandler.h"
#include "../Control/TipoInput.h"
#include <memory>
#include <fstream>
#include <gtest/gtest.h>

TEST(ListaAttivitaTest, AddAttivitaTest) {
    auto nuovaAttivita = std::make_unique<AttivitaSemplice>(AttivitaSemplice("Esempio di attività semplice"));
    std::unique_ptr<ListaAttivita> listaAttivita = std::make_unique<ListaAttivita>();
    listaAttivita->addAttivita(std::move(nuovaAttivita));
    auto listaRisultato = listaAttivita->getListaAttivita();
    ASSERT_EQ(1, listaRisultato.size());
    ASSERT_EQ("Esempio di attività semplice", listaRisultato[0]->getDescrizione());
    ASSERT_FALSE(listaRisultato[0]->isCompletata());
}
