#pragma once
#include "plik.h"
using namespace std;
//klasa odpawiadaj�ca za intefejs u�ytkownika
class interfejs
{
	private:

	Baza<string> Dane;
	plik Dane_zewnetrzne;
	void pomoc();

	public:
	bool czekaj_na_polecenie();
};

