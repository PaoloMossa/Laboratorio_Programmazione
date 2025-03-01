//
// Created by Paolo Mossa on 01/03/25.
//

#include <gtest/gtest.h>

#include "../Control/TipoInput.h"

TEST(TipoInputTest, stringToTipoInputTest) {
    std::string stringInput;
    TipoInput tipoInput;

    stringInput = "Nuovo";
    tipoInput = stringToTipoInput(stringInput);
    ASSERT_EQ(TipoInput::Nuovo, tipoInput);

    stringInput = "Modifica";
    tipoInput = stringToTipoInput(stringInput);
    ASSERT_EQ(TipoInput::Modifica, tipoInput);

    stringInput = "Rimuovi";
    tipoInput = stringToTipoInput(stringInput);
    ASSERT_EQ(TipoInput::Rimuovi, tipoInput);

    stringInput = "Esci";
    tipoInput = stringToTipoInput(stringInput);
    ASSERT_EQ(TipoInput::Esci, tipoInput);

    stringInput = "Completa";
    tipoInput = stringToTipoInput(stringInput);
    ASSERT_EQ(TipoInput::Completa, tipoInput);

    stringInput = "????";
    tipoInput = stringToTipoInput(stringInput);
    ASSERT_EQ(TipoInput::Non_valido, tipoInput);
}