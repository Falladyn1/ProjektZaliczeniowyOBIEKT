#pragma once
#include <stdexcept>
#include <string>
#include <windows.h> // Biblioteka do kolorow w konsoli Windows

// Definicje kolorow
#define KOLOR_RESET   7
#define KOLOR_ZIELONY 10
#define KOLOR_CZERWONY 12
#define KOLOR_ZOLTY   14

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
    BledneDaneException() : std::runtime_error("Blad: Podano nieprawidlowe dane wejsciowe.") {}
};

class NieznalezionoElementuException : public std::runtime_error {
public:
    NieznalezionoElementuException(std::string msg) : std::runtime_error("Blad: " + msg) {}
};