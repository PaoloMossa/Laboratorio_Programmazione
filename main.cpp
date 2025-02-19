#include <iostream>

#include "Domain/Attivita.h"
#include "Domain/AttivitaSemplice.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    AttivitaSemplice a = AttivitaSemplice("Fare la spesa", false);
    a.stampa();
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.