
#include "Pojazd_ciê¿arowy.h"
void Pojazd_ciezarowy::dodaj_pojazd()
{
	//Pojazd dane
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

	//Pojazd_ciê¿arowy dane
	cout << "\n" << "\t" << "Podaj liczbê osi: ";
	wejscie(liczba_osi);
	cout << "\n" << "\t" << "Podaj rodzaj kabiny: ";
	wejscie(rodzaj_kabiny);
	cout << "\n" << "\t" << "Podaj Dopuszczaln¹ masê ca³kowit¹(liczba): ";
	wejscie(first);
	cout << "\n" << "\t" << "Podaj Dopuszczaln¹ masê ca³kowit¹(jednostka): ";
	wejscie(second);
	DMC = make_pair(first, second);

};
void Pojazd_ciezarowy::edytuj_pojazd(string VIN)
{
	//Pojazd dane
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

	//Pojazd_ciê¿arowy dane
	cout << "\n" << "\t" << "Podaj liczbê osi: ";
	wejscie(liczba_osi);
	cout << "\n" << "\t" << "Podaj rodzaj kabiny: ";
	wejscie(rodzaj_kabiny);
	cout << "\n" << "\t" << "Podaj Dopuszczaln¹ masê ca³kowit¹(liczba): ";
	wejscie(first);
	cout << "\n" << "\t" << "Podaj Dopuszczaln¹ masê ca³kowit¹(jednostka): ";
	wejscie(second);
	DMC = make_pair(first, second);

};

void Pojazd_ciezarowy::wypisz_pojazd()
{
	//Pojazd dane
	cout << "\n";
	cout << "Numer VIN: " << numer_VIN << " Typ pojazdu: " << typ_pojazdu << " Marka: " << marka << " Model: " << model << " Rok produkcji: "<< rok_produkcji;
	cout << " Prêdkoœæ Maksymalna: " << predkosc_max.first << " " << predkosc_max.second;
	cout << " Przyspieszenie: " << przyspieszenie.first << " " << przyspieszenie.second;
	cout << " Zasieg: " << zasieg.first << " " << zasieg.second;
	cout << " Czas ladowania: " << czas_ladowania.first << " " << czas_ladowania.second;
	//Pojazd_ciê¿arowy dane
	cout << " Liczba osi " << liczba_osi;
	cout << " Rodzaj kabiny: " << rodzaj_kabiny;
	cout << " Dopuszczalna masa ca³kowita pojazdu: " << DMC.first << " " << DMC.second;
	cout << "\n";

};
//eksport ciezarowy
tuple<string, string, string,string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> Pojazd_ciezarowy::eksport()
{
	auto t = make_tuple(typ_pojazdu,numer_VIN,marka,model,rok_produkcji,predkosc_max,przyspieszenie,zasieg,czas_ladowania,liczba_osi,rodzaj_kabiny,DMC);
	return t;

};

Pojazd_ciezarowy::Pojazd_ciezarowy()//pusty konstruktor
{
	//Pojazd dane
	typ_pojazdu = "Pojazd_ciezarowy";
	numer_VIN,marka,model = "N/A";
	rok_produkcji = 0;
	predkosc_max = make_pair(0, "N/A");
	przyspieszenie = make_pair(0, "N/A");
	zasieg = make_pair(0, "N/A");
	czas_ladowania = make_pair(0, "N/A");
	//Pojazd_ciê¿arowy dane
	liczba_osi = 0;
	rodzaj_kabiny = "N/A";
	DMC = make_pair(0, "N/A");
};
//konstruktor z zestawem danych
Pojazd_ciezarowy::Pojazd_ciezarowy(tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> &D)
{
	//Pojazd dane
	typ_pojazdu = "Pojazd_ciezarowy";
	numer_VIN = get<1>(D);
	marka = get<2>(D);
	model = get<3>(D);
	rok_produkcji = get<4>(D);
	predkosc_max = get<5>(D);
	przyspieszenie = get<6>(D);
	zasieg = get<7>(D);
	czas_ladowania = get<8>(D);
	//Pojazd_ciê¿arowy dane
	liczba_osi = get<9>(D);
	rodzaj_kabiny = get<10>(D);
	DMC = get<11>(D);
};



