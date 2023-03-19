#include "Pojazd_osobowy.h"
void Pojazd_osobowy::dodaj_pojazd()
{
	//Pojazd dane
	typ_pojazdu = " Pojazd_osobowy";
	cout << "\n" << "\t" << "Podaj numer VIN pojazdu: ";
	wejscie(numer_VIN);
	cout << "\n" << "\t" << "Podaj markê: ";
	wejscie(marka);
	cout << "\n" << "\t" << "Podaj model: ";
	wejscie(model);
	cout << "\n" << "\t" << "Podaj rok produkcji: ";
	wejscie(rok_produkcji);
	double first;
	string second;
	cout << "\n" << "\t" << "Podaj prêdkoœæ maksymaln¹(liczba): ";
	wejscie(first);
	cout << "\n" << "\t" << "Podaj prêdkoœæ maksymaln¹(jednostka): ";
	wejscie(second);
	predkosc_max = make_pair(first, second);
	cout << "\n" << "\t" << "Podaj przyspiesznie(liczba): ";
	wejscie(first);
	cout << "\n" << "\t" << "Podaj przyspiesznie(jednostka): ";
	wejscie(second);
	przyspieszenie = make_pair(first, second);
	cout << "\n" << "\t" << "Podaj zasiêg(liczba): ";
	wejscie(first);
	cout << "\n" << "\t" << "Podaj zasiêg(jednostka): ";
	wejscie(second);
	zasieg = make_pair(first, second);
	cout << "\n" << "\t" << "Podaj czas_ladowania(liczba): ";
	wejscie(first);
	cout << "\n" << "\t" << "Podaj czas_ladowania(jednostka): ";
	wejscie(second);
	czas_ladowania = make_pair(first, second);

	//Pojazd_osobowy dane
	cout << "\n" << "\t" << "Podaj liczbê drzwi: ";
	wejscie(liczba_drzwi);
	cout << "\n" << "\t" << "Podaj rodzaj nadwozia: ";
	wejscie(rodzaj_nadwozia);
	cout << "\n" << "\t" << "Podaj wagê(liczba): ";
	wejscie(first);
	cout << "\n" << "\t" << "Podaj wagê(jednostka): ";
	wejscie(second);
	waga = make_pair(first, second);

};
void Pojazd_osobowy::edytuj_pojazd(string VIN)
{
	//Pojazd dane
	typ_pojazdu = " Pojazd_osobowy";
	cout << "\n" << "\t" << "Podaj numer VIN pojazdu: ";
	numer_VIN=VIN;
	cout << VIN;
	cout << "\n" << "\t" << "Podaj markê: ";
	wejscie(marka);
	cout << "\n" << "\t" << "Podaj model: ";
	wejscie(model);
	cout << "\n" << "\t" << "Podaj rok produkcji: ";
	wejscie(rok_produkcji);
	double first;
	string second;
	cout << "\n" << "\t" << "Podaj prêdkoœæ maksymaln¹(liczba): ";
	wejscie(first);
	cout << "\n" << "\t" << "Podaj prêdkoœæ maksymaln¹(jednostka): ";
	wejscie(second);
	predkosc_max = make_pair(first, second);
	cout << "\n" << "\t" << "Podaj przyspiesznie(liczba): ";
	wejscie(first);
	cout << "\n" << "\t" << "Podaj przyspiesznie(jednostka): ";
	wejscie(second);
	przyspieszenie = make_pair(first, second);
	cout << "\n" << "\t" << "Podaj zasiêg(liczba): ";
	wejscie(first);
	cout << "\n" << "\t" << "Podaj zasiêg(jednostka): ";
	wejscie(second);
	zasieg = make_pair(first, second);
	cout << "\n" << "\t" << "Podaj czas_ladowania(liczba): ";
	wejscie(first);
	cout << "\n" << "\t" << "Podaj czas_ladowania(jednostka): ";
	wejscie(second);
	czas_ladowania = make_pair(first, second);

	//Pojazd_osobowy dane
	cout << "\n" << "\t" << "Podaj liczbê drzwi: ";
	wejscie(liczba_drzwi);
	cout << "\n" << "\t" << "Podaj rodzaj nadwozia: ";
	wejscie(rodzaj_nadwozia);
	cout << "\n" << "\t" << "Podaj wagê(liczba): ";
	wejscie(first);
	cout << "\n" << "\t" << "Podaj wagê(jednostka): ";
	wejscie(second);
	waga = make_pair(first, second);

};

void Pojazd_osobowy::wypisz_pojazd()
{
	//Pojazd dane
	cout << "\n";
	cout << "Numer VIN: " << numer_VIN << " Typ pojazdu: " << typ_pojazdu <<" Marka: " << marka << " Model: " << model << " Rok produkcji: "<< rok_produkcji;
	cout << " Prêdkoœæ Maksymalna: " << predkosc_max.first << " " << predkosc_max.second;
	cout << " Przyspieszenie: " << przyspieszenie.first << " " << przyspieszenie.second;
	cout << " Zasieg: " << zasieg.first << " " << zasieg.second;
	cout << " Czas ladowania: " << czas_ladowania.first << " " << czas_ladowania.second;
	//Pojazd_osobowy dane
	cout << " Liczba Drzwi: " << liczba_drzwi;
	cout << " Rodzaj nadwozia: " << rodzaj_nadwozia;
	cout << " Waga pojazdu: " << waga.first<<" " << waga.second;
	cout << "\n";

};

//eksport_osobowy
tuple<string, string, string,string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> Pojazd_osobowy::eksport()
{
	auto t = make_tuple(typ_pojazdu,numer_VIN,marka, model, rok_produkcji, predkosc_max, przyspieszenie, zasieg, czas_ladowania, liczba_drzwi,rodzaj_nadwozia,waga);
	return t;

};

Pojazd_osobowy::Pojazd_osobowy()//pusty konstruktor
{
	//Pojazd dane
	typ_pojazdu = "Pojazd_osobowy";
	numer_VIN, marka, model = "N/A";
	rok_produkcji = 0;
	predkosc_max = make_pair(0, "N/A");
	przyspieszenie = make_pair(0, "N/A");
	zasieg = make_pair(0, "N/A");
	czas_ladowania = make_pair(0, "N/A");
	//Pojazd_osobowy dane
	liczba_drzwi = 0;
	rodzaj_nadwozia = "N/A";
	waga = make_pair(0, "N/A");
}
Pojazd_osobowy::Pojazd_osobowy(tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> &D)//konstruktor z zestawem danych
{
	//Pojazd dane
	typ_pojazdu = "Pojazd_osobowy";
	numer_VIN = get<1>(D);
	marka = get<2>(D);
	model = get<3>(D);
	rok_produkcji = get<4>(D);
	predkosc_max = get<5>(D);
	przyspieszenie = get<6>(D);
	zasieg = get<7>(D);
	czas_ladowania = get<8>(D);
	//Pojazd_osobowy dane
	liczba_drzwi = get<9>(D);
	rodzaj_nadwozia = get<10>(D);
	waga = get<11>(D);
}


