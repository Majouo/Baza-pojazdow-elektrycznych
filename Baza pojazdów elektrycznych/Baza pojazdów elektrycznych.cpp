// codepage:Ą†©ˆä˘˜ľ«¤Ź¨ťăŕ—˝Ť
//Michał Maj Re2
//Baza pojazdów elektrycznych
#include "Pojazd.h"
#include "Pojazd_ciężarowy.h"
#include "Pojazd_osobowy.h"
#include "Baza.h"
#include "plik.h"
#include "interfejs.h"
#include <locale.h>


int main()
{
	setlocale(LC_CTYPE, "Polish");//Polskie znaki
	interfejs Wykonaj;
	while(Wykonaj.czekaj_na_polecenie()==0);
	return 0;
}
