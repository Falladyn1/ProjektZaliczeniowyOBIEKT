#include "WagonPrzedzialowy.h"
#include <iostream>
#include <iomanip>

using namespace std;

WagonPrzedzialowy::WagonPrzedzialowy(int _nr) 
	: Wagon(_nr), liczbaPrzedzialow(10) {
	generujMiejsca();
};

void WagonPrzedzialowy::generujMiejsca() {
	int licznik = 1;
	for (int i = 1; i < liczbaPrzedzialow; i++) {
		siedzenia.push_back(Miejsce(licznik++, i, 'A', TypMiejsca::OKNO, true, false));
		siedzenia.push_back(Miejsce(licznik++, i, 'B', TypMiejsca::SRODEK, true, false));
		siedzenia.push_back(Miejsce(licznik++, i, 'C', TypMiejsca::KORYTARZ, true, false));

		siedzenia.push_back(Miejsce(licznik++, i, 'D', TypMiejsca::KORYTARZ, true, false));
		siedzenia.push_back(Miejsce(licznik++, i, 'E', TypMiejsca::SRODEK, true, false));
		siedzenia.push_back(Miejsce(licznik++, i, 'F', TypMiejsca::OKNO, true, false));
	}
}

void WagonPrzedzialowy::wyswietlSchemat() {
    cout << "\n      SCHEMAT WAGONU PRZEDZIALOWEGO NR " << numerWagonu << "\n";
    cout << "      _________________________________________\n";

    for (int p = 0; p < liczbaPrzedzialow; ++p) {
        int baseIdx = p * 8; // 8 miejsc na przedzia³

        cout << "     | PRZEDZIAL NR " << setw(2) << (p + 1) << "                       |\n";
        cout << "     | ";

        for (int i = 0; i < 4; ++i) {
            const Miejsce& m = siedzenia[baseIdx + i];
            if (m.czyWolne())
                cout << "[" << setw(2) << setfill('0') << m.pobierzNumer() << "]";
            else
                cout << "[XX]";
        }
        cout << " |\n";

        cout << "     | ";
        for (int i = 4; i < 8; ++i) {
            const Miejsce& m = siedzenia[baseIdx + i];
            if (m.czyWolne())
                cout << "[" << setw(2) << setfill('0') << m.pobierzNumer() << "]";
            else
                cout << "[XX]";
        }
        cout << " |\n";
        cout << "     |_________________________________________|\n";
    }

    cout << "     |                                         |\n";
    cout << "     |                KORYTARZ                 |\n";
    cout << "     |_________________________________________|\n\n";
}
