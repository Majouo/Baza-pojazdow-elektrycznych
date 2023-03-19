#include "plik.h"
//funkcje prywatne//
//zapisywanie do pliku danych


void plik::wypisz_osobowy(tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> &t)
{
	
	//pierwsze 4 stringi
	//static_cast<__int64> ze wzglêdu na rzutowanie
	

		Dane.write(get<0>(t).c_str(), get<0>(t).size() + static_cast<__int64>(1));

		Dane.write(get<1>(t).c_str(), get<1>(t).size() + static_cast<__int64>(1));

		Dane.write(get<2>(t).c_str(), get<2>(t).size() + static_cast<__int64>(1));

		Dane.write(get<3>(t).c_str(), get<3>(t).size() + static_cast<__int64>(1));

	// rok produkcji

		Dane.write((char*)&get<4>(t), sizeof(unsigned int));

	//4 pary
	
		Dane.write((char*)&get<5>(t).first, sizeof(double));
		Dane.write(get<5>(t).second.c_str(), get<5>(t).second.size() + static_cast<__int64>(1));

		Dane.write((char*)&get<6>(t).first, sizeof(double));
		Dane.write(get<6>(t).second.c_str(), get<6>(t).second.size() + static_cast<__int64>(1));

		Dane.write((char*)&get<7>(t).first, sizeof(double));
		Dane.write(get<7>(t).second.c_str(), get<7>(t).second.size() + static_cast<__int64>(1));

		Dane.write((char*)&get<8>(t).first, sizeof(double));
		Dane.write(get<8>(t).second.c_str(), get<8>(t).second.size() + static_cast<__int64>(1));

	//Specjalizacja//
	Dane.write((char*)&get<9>(t), sizeof(unsigned int));

	Dane.write(get<10>(t).c_str(), get<10>(t).size() + static_cast<__int64>(1));

	Dane.write((char*)&get<11>(t).first, sizeof(double));
	Dane.write(get<11>(t).second.c_str(), get<11>(t).second.size() + static_cast<__int64>(1));

};
//zapisywanie do pliku danych
void plik::wypisz_ciezarowy(tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> &t)
{
	wypisz_osobowy(t);//taki sam typ i iloœæ danych w specjalizacji

};

string plik::odczytaj_typ_pojazdu()
{
	string temp;
	getline(Dane, temp, '\0');
	return temp;
};
//wczytywanie do programu danych
tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> plik::odczytaj_osobowy(string &typ)
{
	string numer_VIN, marka, model;
	unsigned int rok_produkcji;
	double first;
	string second;
	//sk³adnia pary <wartoœæ,jednostka> 
	pair<double, string> predkosc_max;
	pair<double, string> przyspieszenie;
	pair<double, string> zasieg;
	pair<double, string> czas_ladowania;
	//specjalizacja
	unsigned int spec_1;
	string spec_2;
	pair<double, string> spec_3;

	//3 stringi

		getline(Dane, numer_VIN, '\0');
		getline(Dane, marka, '\0');
		getline(Dane, model, '\0');

	//rok produkcji

		Dane.read((char*)&rok_produkcji, sizeof(unsigned int));

	//4 pary

		Dane.read((char*)&first, sizeof(double));
		getline(Dane, second, '\0');
		predkosc_max = make_pair(first, second);

		Dane.read((char*)&first, sizeof(double));
		getline(Dane, second, '\0');
		przyspieszenie = make_pair(first, second);

		Dane.read((char*)&first, sizeof(double));
		getline(Dane, second, '\0');
		zasieg = make_pair(first, second);

		Dane.read((char*)&first, sizeof(double));
		getline(Dane, second, '\0');
		czas_ladowania = make_pair(first, second);

	//specjalizacja

		Dane.read((char*)&spec_1, sizeof(unsigned int));

		getline(Dane, spec_2, '\0');

		Dane.read((char*)&first, sizeof(double));
		getline(Dane, second, '\0');
		spec_3 = make_pair(first, second);
	// zwaracanie tuple
		return make_tuple(typ, numer_VIN, marka, model, rok_produkcji, predkosc_max, przyspieszenie, zasieg, czas_ladowania, spec_1, spec_2, spec_3);

};
//wczytywanie do programu danych
tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> plik::odczytaj_ciezarowy(string &typ)
{
	return odczytaj_osobowy(typ);//taki sam typ i iloœæ danych w specjalizacji
};
//funkcje publiczne//
void plik::odczytaj_baza(Baza <string> &baza,string &plik)
{
	Dane.open(plik, std::ios::in | std::ios::binary);
	if (Dane.good() == true)
	{
		while (Dane.eof()==false)
		{

			string typ = odczytaj_typ_pojazdu();
			//sprawdzanie typu pojazdu z pliku i wczytywanie do programu
			if (typ.find("Pojazd_osobowy")!=string::npos)
			{
				tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> t=odczytaj_osobowy(typ);
				baza.dodaj_osobowy(t);

			}
			else if (typ.find("Pojazd_ciezarowy")!= string::npos)
			{
				tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> t=odczytaj_ciezarowy(typ);
				baza.dodaj_ciezarowy(t);
			}
			else if (typ == "\0")
			{
				break;
			}
			else
			{
				cout<<"\n" << "Nie mo¿na odczytaæ pojazdu";
				break;
			}

		}
		cout << "\n" << "Poprawnie wczytano  plik";
	}
	else
	{
		cout << "\n" << "Nie mo¿na wczytaæ podanego pliku";
	}
	Dane.close();
	
}
void plik::zapisz_baza(Baza <string>& B, string& plik)
{
	remove(plik.c_str());//usuñ plik je¿eli istnieje
	Dane.open(plik, std::ios::out | std::ios::binary);
	if (Dane.good() == true)
	{

		map <string, Pojazd*> dat = B.eksport_baza();
		for (auto it = dat.begin(); it != dat.end(); ++it) {

			Pojazd_osobowy* pojazd_osobowy = dynamic_cast<Pojazd_osobowy*>(it->second);		 //rzutowanie dynamiczne
			Pojazd_ciezarowy* pojazd_ciezarowy = dynamic_cast<Pojazd_ciezarowy*>(it->second);//
			if (pojazd_osobowy)
			{
				tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> t = pojazd_osobowy->eksport();	
				wypisz_osobowy(t);
				
			}
			else if (pojazd_ciezarowy)
			{
				tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> t = pojazd_ciezarowy->eksport();
				wypisz_ciezarowy(t);
			}
			else
			{
				cout << "\n" << "Z³y typ pojazdu";
			}
		}
		cout << "\n" << "Poprawnie wczytano/utworzyono plik";
	}
	else
	{
		cout << "\n" << "Nie mo¿na wczytaæ/utworzyæ podanego pliku";
	}
	Dane.close();


};

