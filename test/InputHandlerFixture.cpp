//
// Created by Paolo Mossa on 01/03/25.
//
#include "gtest/gtest.h"
#include "../Control/InputHandler.h"
#include "../Domain/ListaAttivita.h"
#include "../Domain/AttivitaSemplice.h"




class InputHandlerSuite : public testing::Test {
protected:
    ListaAttivita listaAttivita;
    std::unique_ptr<InputHandler> inputHandler;
    virtual void SetUp() {
        listaAttivita.addAttivita(std::make_unique<AttivitaSemplice>("Esempio di attività semplice"));
        inputHandler = std::make_unique<InputHandler>(listaAttivita);
    }
};

TEST_F(InputHandlerSuite, TestInputNonValido) {
    inputHandler->handleInput(TipoInput::Non_valido);

    //Must be verified if the fields of inputHandler didn't change, i.e. if listaAttivita.size() == 0
    ASSERT_EQ(listaAttivita.size(), 1);
    ASSERT_EQ(listaAttivita.getListaAttivita()[0]->getDescrizione(), "Esempio di attività semplice");
}

TEST_F(InputHandlerSuite, TestNuovaAttivitaSemplice){
    std::stringstream ss;
    ss << "Semplice" << std::endl << "test"<< std::endl; // Simulate user input "Semplice" and then "test"
    std::streambuf* oldCout = std::cin.rdbuf(ss.rdbuf());
    inputHandler->handleInput(TipoInput::Nuovo);
    std::cin.rdbuf(oldCout);

    ASSERT_EQ(2, listaAttivita.size());
    //listaAttivita[0] was added in SetUp() method
    ASSERT_EQ("test",listaAttivita.getListaAttivita()[1]->getDescrizione());
}

TEST_F(InputHandlerSuite, TestRimuoviAttivita) {
    std::stringstream ss;
    ss << "0" << std::endl; // Simulate user input "0"
    std::streambuf* oldCout = std::cin.rdbuf(ss.rdbuf());
    inputHandler->handleInput(TipoInput::Rimuovi);
    std::cin.rdbuf(oldCout);

    ASSERT_EQ(0, listaAttivita.size());
}

TEST_F(InputHandlerSuite, TestCompletaAttivita) {
    std::stringstream ss;
    ss << "0" << std::endl; // Simulate user input "0"
    std::streambuf* oldCout = std::cin.rdbuf(ss.rdbuf());
    inputHandler->handleInput(TipoInput::Completa);
    std::cin.rdbuf(oldCout);

    ASSERT_TRUE(listaAttivita.getListaAttivita()[0]->isCompletata());
}

TEST_F(InputHandlerSuite, TestModificaAttivita) {
    std::stringstream ss;
    ss << "0" << std::endl << "test" << std::endl; // Simulate user input "0" and then "test""
    std::streambuf* oldCout = std::cin.rdbuf(ss.rdbuf());
    inputHandler->handleInput(TipoInput::Modifica);
    std::cin.rdbuf(oldCout);

    ASSERT_EQ("test",listaAttivita.getListaAttivita()[0]->getDescrizione());
}

TEST_F(InputHandlerSuite, TestModificaIndiceNegativo) {
    std::stringstream ss;
    ss << "-1" << std::endl << "test" << std::endl; // Simulate user input "0" and then "test""
    std::streambuf* oldCout = std::cin.rdbuf(ss.rdbuf());
    inputHandler->handleInput(TipoInput::Modifica);
    std::cin.rdbuf(oldCout);

    //The description must not change and stay the same as is was in SetUp() method
    ASSERT_EQ("Esempio di attività semplice",listaAttivita.getListaAttivita()[0]->getDescrizione());
}

TEST_F(InputHandlerSuite, TestModificaIndiceFuoriPortata) {
    std::stringstream ss;
    ss << "99999" << std::endl << "test" << std::endl; // Simulate user input "0" and then "test""
    std::streambuf* oldCout = std::cin.rdbuf(ss.rdbuf());
    inputHandler->handleInput(TipoInput::Modifica);
    std::cin.rdbuf(oldCout);

    //The description must not change and stay the same as is was in SetUp() method
    ASSERT_EQ("Esempio di attività semplice",listaAttivita.getListaAttivita()[0]->getDescrizione());
}