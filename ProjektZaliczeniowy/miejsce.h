#pragma once
enum class TypMiejsca {
	OKNO,
	KORYTARZ,
	SRODEK,
};

class miejsce{
private:
	int numerWagonu;
	bool dostepnosc = true;
	bool czyPrzedzial;
	bool czyStolik;
	TypMiejsca rodzaj;
public:
	miejsce(TypMiejsca, bool, bool);

	bool pobierzDostepnoscMiejsca();
};

