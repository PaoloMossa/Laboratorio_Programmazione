//
// Created by Paolo Mossa on 01/03/25.
//
#include <fstream>

#include "gtest/gtest.h"
#include "../Persistence/GestoreFile.h"
#include "../Domain/AttivitaImportante.h"
#include "../Domain/AttivitaSemplice.h"


class GestoreFileSuite : public testing::Test {
protected:
    std::string nomeFile = "test_attivita.txt";
    GestoreFile gestoreFile;

    GestoreFileSuite() : gestoreFile(nomeFile) {}

    void SetUp() override {
        // Create a sample file for testing
        std::ofstream file(nomeFile);
        file << "Semplice;Attività semplice;1" << std::endl;
        file << "Importante;Attività importante;0" << std::endl;
        file.close();
    }
    void TearDown() override {
        // Remove the test file
        remove(nomeFile.c_str());
    }
};

TEST_F(GestoreFileSuite, TestCaricaDaFile) {
    auto attivitaList = gestoreFile.caricaDaFile();

    ASSERT_EQ(attivitaList.size(), 2);

    ASSERT_EQ(attivitaList[0]->getType(), "Semplice");
    ASSERT_EQ(attivitaList[1]->getType(), "Importante");

    ASSERT_EQ(attivitaList[0]->getDescrizione(), "Attività semplice");
    ASSERT_EQ(attivitaList[1]->getDescrizione(), "Attività importante");

    ASSERT_TRUE(attivitaList[0]->isCompletata());
    ASSERT_FALSE(attivitaList[1]->isCompletata());
}

TEST_F(GestoreFileSuite, TestSalvaSuFile) {
    auto attivitaList = std::vector<std::unique_ptr<Attivita>>();
    attivitaList.push_back(std::make_unique<AttivitaSemplice>("Attività 1", false));
    attivitaList.push_back(std::make_unique<AttivitaImportante>("Attività 2", true));

    ASSERT_TRUE(gestoreFile.salvaSuFile(attivitaList));

    // Check if the file was written correctly
    std::ifstream file(nomeFile);
    ASSERT_TRUE(file.is_open());

    std::string riga;
    std::vector<std::string> righe;
    while (std::getline(file, riga)) {
        righe.push_back(riga);
    }
    file.close();

    ASSERT_EQ(righe.size(), 2);
    ASSERT_EQ(righe[0], "Semplice;Attività 1;0");
    ASSERT_EQ(righe[1], "Importante;Attività 2;1");

}

TEST_F(GestoreFileSuite, TestCaricaDaFile_EmptyFile) {
    // Create an empty file
    std::ofstream file(nomeFile);
    file.close();

    auto attivitaList = gestoreFile.caricaDaFile();
    ASSERT_EQ(attivitaList.size(), 0);
}

TEST_F(GestoreFileSuite, TestCaricaDaFile_InvalidDataInFile) {
    // Create a file with invalid data
    std::ofstream file(nomeFile);
    file << "Invalid data" << std::endl;
    file.close();

    auto attivitaList = gestoreFile.caricaDaFile();
    // The invalid line should be skipped, resulting in an empty list
    ASSERT_EQ(attivitaList.size(), 0);
}