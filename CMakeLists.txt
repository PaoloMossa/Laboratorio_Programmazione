cmake_minimum_required(VERSION 3.30)
project(LabProgrammazione)

set(CMAKE_CXX_STANDARD 20)

add_executable(LabProgrammazione main.cpp
        Domain/Attivita.h
        Domain/AttivitaSemplice.cpp
        Domain/AttivitaSemplice.h
        Persistence/GestoreFile.cpp
        Persistence/GestoreFile.h
        Domain/ListaAttivita.cpp
        Domain/ListaAttivita.h)
