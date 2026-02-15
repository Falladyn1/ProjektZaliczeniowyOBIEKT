#pragma once
#include <vector>
#include <string>

class Trasa {
private:
    std::string nazwaRelacji;
    std::vector<std::string> stacje;
public:
    Trasa(std::string nazwa = "Nieznana");
    void dodajStacje(std::string nazwaStacji);
    void wyswietlPrzebieg() const;
    const std::vector<std::string>& pobierzStacje() const { return stacje; }
};