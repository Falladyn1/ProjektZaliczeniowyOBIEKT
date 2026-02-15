#pragma once
#include <windows.h> 
#include <stdexcept>
#include <string>

#define KOLOR_RESET   7
#define KOLOR_ZIELONY 10
#define KOLOR_CZERWONY 12
#define KOLOR_ZOLTY   14
#define KOLOR_NIEBIESKI 11

inline void ustawKolor(int k) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}

// Proste klasy wyj¹tków
class BladRezerwacji : public std::runtime_error {
public:
    BladRezerwacji(const std::string& wiadomosc) : std::runtime_error(wiadomosc) {}
};

class BladDanych : public std::runtime_error {
public:
    BladDanych(const std::string& wiadomosc) : std::runtime_error(wiadomosc) {}
};