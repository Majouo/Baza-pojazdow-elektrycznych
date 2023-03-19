#pragma once
#include <map>
#include "Pojazd.h"
#include "Pojazd_osobowy.h"
#include "Pojazd_ciê¿arowy.h"

//klasa operacji na kontenerze 
template <typename U>
class Baza
{
	private:
		map<U,Pojazd*>Dane;

	public:
		//przekazywanie wskaŸników Pojazdu do kontenera
		void dodaj_osobowy()
		{
			Pojazd* wsk = new Pojazd_osobowy;

			wsk->dodaj_pojazd();
			Dane.try_emplace(wsk->zwroc_klucz(), wsk);

		}
		void dodaj_osobowy(tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> &t)
		{
			Pojazd* wsk = new Pojazd_osobowy(t);

			Dane.try_emplace(wsk->zwroc_klucz(), wsk);

		}

		void dodaj_ciezarowy()
		{
			Pojazd* wsk = new Pojazd_ciezarowy;

			wsk->dodaj_pojazd();
			Dane.try_emplace(wsk->zwroc_klucz(), wsk);
		}
		void dodaj_ciezarowy(tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> &t)
		{
			Pojazd* wsk = new Pojazd_ciezarowy(t);

			Dane.try_emplace(wsk->zwroc_klucz(), wsk);
		}
		////////////////////////////////////////////
		void edytuj(U& VIN)//edycja konkretnego pojazdu
		{
			auto szukana = Dane.find(VIN);
			if (szukana != Dane.end())
			{
				Pojazd* wsk = Dane.at(VIN);
				wsk->edytuj_pojazd(VIN);

				Dane.emplace(wsk->zwroc_klucz(), wsk);
			}
			else
			{
				cout << "\n" << "Nie istnieje pojazd o podanym numerze VIN";
			}
		};
		void wypisz(U &VIN)// wypisuje konkretny element
		{
			auto szukana = Dane.find(VIN);
			if (szukana != Dane.end())
			{
				Dane[VIN]->wypisz_pojazd();
			}
			else
			{
				cout << "\n" << "Nie istnieje pojazd o podanym numerze VIN";
			}

		}
		void wypisz()// wypisuje wszystkie elementy Bazy
		{
			for (auto it = Dane.begin(); it != Dane.end(); ++it) {
				it->second->wypisz_pojazd();
			}
		};
		map <U, Pojazd*> eksport_baza()
		{
			return Dane;
		}
		void usun_element(U &VIN)
		{
			auto szukana = Dane.find(VIN);
			if (szukana != Dane.end())
			{
				delete szukana->second;//usuwanie wskaŸnika
				Dane.erase(szukana);
			}
			else
			{
				cout << "\n" << "Nie istnieje pojazd o podanym numerze VIN";
			}

		}
		~Baza()
		{
			for (auto it = Dane.begin(); it != Dane.end(); ++it) {
				delete it->second;//usuwanie wskaŸnika
			}

		}

		
};