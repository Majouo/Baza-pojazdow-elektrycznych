#include "interfejs.h"
#include <functional>
void interfejs::pomoc()
{
	cout << "\n" << "\t" << "\t" << "Lista Polece�:";
	cout << "\n" << "\t" << "Pomoc - wy�witlenie listy polece�";
	cout << "\n" << "\t" << "Wyczy�� - czyszczenie konsoli";
	cout << "\n" << "\t" << "Cofnij - pozwala na cofni�cie z polecenia gdzie trzeba poda� VIN(Usu�_pojazd,Wypisz_pojazd,Edytuj_pojazd) lub nazw� pliku(Dodaj_plik,Wypisz_plik)";
	cout << "\n" << "\t" << "Wyjd� - poprawne wy��czenie programu";
	cout << "\n" << "\t" << "Dodaj_samoch�d - dodanie samochodu osobowego do bazy danych";
	cout << "\n" << "\t" << "Dodaj_ci�ar�wk� - dodanie pojazdu ci�arowego do bazy danych";
	cout << "\n" << "\t" << "Usu�_pojazd - usuni�cie pojazdu z bazy danych";
	cout << "\n" << "\t" << "Edytuj_pojazd - Edytowanie danych konkretnego pojazdu";
	cout << "\n" << "\t" << "Wypisz_pojazd - Wypisanie danych pojazdu";
	cout << "\n" << "\t" << "Wypisz_pojazdy - Wypisanie danych wszystkich pojazd�w";
	cout << "\n" << "\t" << "Dodaj_plik - pobieranie danych z pliku";
	cout << "\n" << "\t" << "Wypisz_plik - wysy�anie danych do pliku";
	cout << "\n";
};
bool interfejs::czekaj_na_polecenie()
{
	string polecenie;
	string temp;
	cout<< "\n" << "Podaj polecenie: ";
	wejscie(polecenie);
	if (polecenie == "Dodaj_samochod")
	{
		Dane.dodaj_osobowy();
	}
	else if (polecenie == "Dodaj_ciezarowke")
	{
		Dane.dodaj_ciezarowy();
	}
	else if (polecenie == "Edytuj_pojazd")
	{
		cout << "\n" << "\t" << "Podaj numer VIN edytowanego pojazdu: ";
		wejscie(temp);
		if (temp == "Cofnij") return 0;
		Dane.edytuj(temp);
	}
	else if (polecenie == "Usun_pojazd")
	{
		cout << "\n" << "\t" << "Podaj numer VIN usuwanego pojazdu: ";
		wejscie(temp);
		if (temp == "Cofnij") return 0;
		Dane.usun_element(temp);
	}
	else if (polecenie == "Wypisz_pojazd")
	{
		cout << "\n" << "\t" << "Podaj numer VIN wypisywanego pojazdu: ";
		wejscie(temp);
		if (temp == "Cofnij") return 0;
		Dane.wypisz(temp);
	}
	else if (polecenie == "Wypisz_pojazdy")
	{
		Dane.wypisz();
	}
	else if (polecenie == "Dodaj_plik")
	{
		cout << "\n" << "\t" << "Podaj nazw� pliku z kt�rego nale�y pobra� dane: ";
		wejscie(temp);
		if (temp == "Cofnij") return 0;
		Dane_zewnetrzne.odczytaj_baza(Dane, temp);
	}
	else if (polecenie == "Wypisz_plik")
	{
		cout << "\n" << "\t" << "Podaj nazw� pliku do kt�rego nale�y wypisa� dane: ";
		wejscie(temp);
		if (temp == "Cofnij") return 0;
		Dane_zewnetrzne.zapisz_baza(Dane, temp);
	}
	else if (polecenie == "Wyczysc")
	{
		system("cls");
	}
	else if (polecenie == "Pomoc")
	{
		pomoc();
	}
	else if (polecenie == "Wyjdz")
	{
		return 1;
	}
	else
	{
		cout << "\n" << "Z�e polecenie. Wprowad� ponownie polecenie";
	}
	return 0;

};