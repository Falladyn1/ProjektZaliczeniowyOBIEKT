#pragma once
#include <vector>
#include <string>

using namespace std;

class Trasa {
private:
    string nazwaRelacji;
    vector<string> stacje;

public:
    Trasa(string nazwa);
    void dodajStacje(string nazwaStacji);
    void wyswietlPrzebieg();
    vector<string>& pobierzStacje();
};