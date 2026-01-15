#include "miejsce.h"

miejsce::miejsce(TypMiejsca _rodzaj, bool _czyPrzedzial, bool _czyStolik) {
	rodzaj = _rodzaj;
	czyPrzedzial = _czyPrzedzial;
	czyStolik = _czyStolik;
}

bool miejsce::pobierzDostepnoscMiejsca() {
	return dostepnosc;
}