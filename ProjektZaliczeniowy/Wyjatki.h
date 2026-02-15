#pragma once
#include <windows.h>
#include <stdexcept>
#include <string>

using namespace std;

#define KOLOR_RESET   7
#define KOLOR_ZIELONY 10
#define KOLOR_CZERWONY 12
#define KOLOR_ZOLTY   14
#define KOLOR_NIEBIESKI 11

inline void ustawKolor(int k) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}

class BladRezerwacji : public runtime_error {
public:
    BladRezerwacji(string wiadomosc) : runtime_error(wiadomosc) {}
};

class BladDanych : public runtime_error {
public:
    BladDanych(string wiadomosc) : runtime_error(wiadomosc) {}
};