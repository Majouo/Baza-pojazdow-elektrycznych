#include "interfejs.h"
#include <functional>
void interfejs::pomoc()
{
	cout << "\n" << "\t" << "\t" << "Lista Poleceñ:";
	cout << "\n" << "\t" << "Pomoc - wyœwitlenie listy poleceñ";
	cout << "\n" << "\t" << "Wyczyœæ - czyszczenie konsoli";
	cout << "\n" << "\t" << "Cofnij - pozwala na cofniêcie z polecenia gdzie trzeba podaæ VIN(Usuñ_pojazd,Wypisz_pojazd,Edytuj_pojazd) lub nazwê pliku(Dodaj_plik,Wypisz_plik)";
	cout << "\n" << "\t" << "WyjdŸ - poprawne wy³¹czenie programu";
	cout << "\n" << "\t" << "Dodaj_samochód - dodanie samochodu osobowego do bazy danych";
	cout << "\n" << "\t" << "Dodaj_ciê¿arówkê - dodanie pojazdu ciê¿arowego do bazy danych";
	cout << "\n" << "\t" << "Usuñ_pojazd - usuniêcie pojazdu z bazy danych";
	cout << "\n" << "\t" << "Edytuj_pojazd - Edytowanie danych konkretnego pojazdu";
	cout << "\n" << "\t" << "Wypisz_pojazd - Wypisanie danych pojazdu";
	cout << "\n" << "\t" << "Wypisz_pojazdy - Wypisanie danych wszystkich pojazdów";
	cout << "\n" << "\t" << "Dodaj_plik - pobieranie danych z pliku";
	cout << "\n" << "\t" << "Wypisz_plik - wysy³anie danych do pliku";
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
		cout << "\n" << "\t" << "Podaj nazwê pliku z którego nale¿y pobraæ dane: ";
		wejscie(temp);
		if (temp == "Cofnij") return 0;
		Dane_zewnetrzne.odczytaj_baza(Dane, temp);
	}
	else if (polecenie == "Wypisz_plik")
	{
		cout << "\n" << "\t" << "Podaj nazwê pliku do którego nale¿y wypisaæ dane: ";
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
		cout << "\n" << "Z³e polecenie. WprowadŸ ponownie polecenie";
	}
	return 0;

};