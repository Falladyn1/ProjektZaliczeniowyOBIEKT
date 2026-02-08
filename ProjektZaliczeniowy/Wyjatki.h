#pragma once
#include <stdexcept>
#include <string>

// Wyj¹tek rzucany, gdy ktoœ chce usi¹œæ na zajêtym miejscu
class MiejsceZajeteException : public std::runtime_error {
public:
    MiejsceZajeteException(int nr) : std::runtime_error("Blad: Miejsce " + std::to_string(nr) + " jest juz zajete!") {}
};

// Gdy u¿ytkownik wpisze np. literê zamiast cyfry
class BledneDaneException : public std::runtime_error {
public:
    BledneDaneException() : std::runtime_error("Blad: Podano nieprawidlowe dane wejsciowe.") {}
};

// Gdy szukamy wagonu/miejsca, którego nie ma w poci¹gu
class NieznalezionoElementuException : public std::runtime_error {
public:
    NieznalezionoElementuException(std::string msg) : std::runtime_error("Blad: " + msg) {}
};