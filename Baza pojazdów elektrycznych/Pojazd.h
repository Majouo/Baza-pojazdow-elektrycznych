#pragma once
#include <iostream>
#include <string>
#include <utility>
#include "funkcje.h"
using namespace std;
//klasa wirtualna obiektów typu pojazd
class Pojazd
{

	protected:
		string typ_pojazdu,numer_VIN,marka, model;
		unsigned int rok_produkcji;
		//sk³adnia pary <wartoœæ,jednostka> 
		pair<double, string> predkosc_max;
		pair<double, string> przyspieszenie;
		pair<double, string> zasieg;
		pair<double, string> czas_ladowania;

	public:
		virtual tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> eksport()=0;
		virtual void dodaj_pojazd() = 0;
		virtual void edytuj_pojazd(string VIN) = 0;
		virtual void wypisz_pojazd() = 0;
		string zwroc_klucz(); // kluczem jest numer VIN

};

