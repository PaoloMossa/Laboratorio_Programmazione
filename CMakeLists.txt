cmake_minimum_required(VERSION 3.30)
project(LabProgrammazione)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)

set(SOURCE_FILES Domain/Attivita.h
        Domain/AttivitaSemplice.cpp
        Domain/AttivitaSemplice.h
        Persistence/GestoreFile.cpp
        Persistence/GestoreFile.h
        Domain/ListaAttivita.cpp
        Domain/ListaAttivita.h
        Domain/AttivitaImportante.cpp
        Domain/AttivitaImportante.h
        Control/InputHandler.cpp
        Control/InputHandler.h
        Control/TipoInput.cpp
        Control/TipoInput.h)
add_executable(LabProgrammazione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(LabProgrammazione core)

#add_executable(LabProgrammazione main.cpp
#        Domain/Attivita.h
#        Domain/AttivitaSemplice.cpp
#        Domain/AttivitaSemplice.h
#        Persistence/GestoreFile.cpp
#        Persistence/GestoreFile.h
#        Domain/ListaAttivita.cpp
#        Domain/ListaAttivita.h
#        Domain/AttivitaImportante.cpp
#        Domain/AttivitaImportante.h
#        Control/InputHandler.cpp
#        Control/InputHandler.h
#        Control/TipoInput.cpp
#        Control/TipoInput.h
#        test/test.cpp
#        test/runAllTests.cpp)
