#pragma once
#include <stdexcept>
#include <string>
#include <windows.h> 

#define KOLOR_RESET   7
#define KOLOR_ZIELONY 10
#define KOLOR_CZERWONY 12
#define KOLOR_ZOLTY   14
#define KOLOR_NIEBIESKI 11

inline void ustawKolor(int k) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}

class MiejsceZajeteException : public std::runtime_error {
public:
    MiejsceZajeteException(int nr) : std::runtime_error("Blad: Miejsce " + std::to_string(nr) + " jest juz zajete!") {}
};

class BledneDaneException : public std::runtime_error {
public:
    BledneDaneException(std::string msg = "Podano nieprawidlowe dane wejsciowe.") : std::runtime_error("Blad: " + msg) {}
};

class NieznalezionoElementuException : public std::runtime_error {
public:
    NieznalezionoElementuException(std::string msg) : std::runtime_error("Blad: " + msg) {}
};