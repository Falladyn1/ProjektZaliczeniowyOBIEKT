#include "WagonBezprzedzialowy.h"

wagonBezprzedzialowy::wagonBezprzedzialowy(int _nr, int liczbaRzedow) : Wagon(_nr) {
    for (int r = 1; r <= liczbaRzedow; r++) {
        siedzenia.push_back(Miejsce(r * 10 + 1, r, 'A', TypMiejsca::OKNO, false, true));
        siedzenia.push_back(Miejsce(r * 10 + 2, r, 'B', TypMiejsca::KORYTARZ, false, true));
        siedzenia.push_back(Miejsce(r * 10 + 3, r, 'C', TypMiejsca::KORYTARZ, false, true));
        siedzenia.push_back(Miejsce(r * 10 + 4, r, 'D', TypMiejsca::OKNO, false, true));
    }
}

void genereujMiejsca() {

}