#include "WagonBezprzedzialowy.h"
#include <algorithm>
wagonBezprzedzialowy::wagonBezprzedzialowy(int _nr, int _liczbaRzedow, bool czyStoliki)
    : Wagon(_nr, czyStoliki), liczbaRzedow(_liczbaRzedow) {
    generujMiejsca();
}

void wagonBezprzedzialowy::generujMiejsca() {
    siedzenia.clear();

    for (int r = 1; r <= liczbaRzedow; r++) {


    }
}