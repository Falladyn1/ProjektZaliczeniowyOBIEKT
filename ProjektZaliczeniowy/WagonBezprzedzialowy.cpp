#include "WagonBezprzedzialowy.h"

wagonBezprzedzialowy::wagonBezprzedzialowy(int _nr, bool _stoliki, int _rzedy)
    : Wagon(_nr, _stoliki), liczbaRzedow(20)
{ 
    generujMiejsca();
}

void wagonBezprzedzialowy::generujMiejsca() {
    int nrMiejsca = 1;
    
    for (int rz = 1; rz <= liczbaRzedow; rz++) {
        if (rz == 9 || rz == 11)
            continue;

        char kolumny[] = { 'A','B','C','D' };

        for (char kol : kolumny) {
            TypMiejsca rodzaj = (kol == 'A' || kol == 'D') ? TypMiejsca::OKNO : TypMiejsca::KORYTARZ;

            siedzenia.push_back(Miejsce(
                nrMiejsca++,
                rz,
                kol,
                rodzaj,
                false, // czyPrzedzial
                czySaStoliki //czyStolik
            ));
        }
    }
}