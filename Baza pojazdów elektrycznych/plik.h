#pragma once
#include <fstream>
#include "Baza.h"
//klasa operujaca plikami zewnêtrznymi
class plik
{
	private:
		fstream Dane;

		void wypisz_osobowy(tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> &t);
		void wypisz_ciezarowy(tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> &t);

		string odczytaj_typ_pojazdu();

		//odczytaj_osobowy(string typ)
		tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> odczytaj_osobowy(string &typ);

		//odczytaj_ciezarowy(string typ)
		tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> odczytaj_ciezarowy(string &typ);
	
	public:
		void zapisz_baza(Baza <string>& B, string& plik);
		void odczytaj_baza(Baza <string>& B, string& plik);
};	

