#pragma once
#include "Pojazd.h"
//klasa pochodna od klasy Pojazd
class Pojazd_osobowy :
    public Pojazd
{
    private:
        unsigned int liczba_drzwi;
        string rodzaj_nadwozia;
        //sk³adnia pary <wartoœæ,jednostka>
        pair<double, string> waga;
        

    public:
        void dodaj_pojazd();
        void wypisz_pojazd();
        void edytuj_pojazd(string VIN);
        tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> eksport();
        //konstruktory
        Pojazd_osobowy();
        Pojazd_osobowy(tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> &D);
        
};

