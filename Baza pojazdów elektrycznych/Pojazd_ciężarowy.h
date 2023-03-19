#pragma once
#include "Pojazd.h"
//klasa pochodna od klasy Pojazd
class Pojazd_ciezarowy :  
    public Pojazd
{
    private:
        unsigned int liczba_osi;
        string rodzaj_kabiny;
        //sk³adnia pary <wartoœæ,jednostka>
        pair<double, string> DMC; //Dopuszczalna masa ca³kowita pojazdu


    public:
       
        void dodaj_pojazd();
        void wypisz_pojazd();
        void edytuj_pojazd(string VIN);
        tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> eksport();
        //konstruktory
        Pojazd_ciezarowy();
        Pojazd_ciezarowy(tuple<string, string, string, string, unsigned int, pair<double, string>, pair<double, string>, pair<double, string>, pair<double, string>, unsigned int, string, pair<double, string>> &D);
        
};

