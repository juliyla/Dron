#ifndef DRON_HH
#define DRON_HH

#include<iostream>
#include "Prostopadloscian.hh"
#include "InterfejsDrona.hh"
#include "Sruba.hh"
#include "Przeszkoda.hh"

class Dron: public InterfejsDrona, public Prostopadloscian {
protected: 
Sruba sruba1; 
Sruba sruba2; 
double promien;
public:
    Dron(Wektor<double, 3>* tabP, Wektor<double, 3>* tabS, Wektor<double, 3> WSrodek, MacierzOb& MOrientacja,drawNS::APIGnuPlot3D* Obiekt) : Prostopadloscian(tabP, WSrodek, MOrientacja,Obiekt), sruba1(Obiekt, tabS, WSrodek, MOrientacja), sruba2(Obiekt, tabS, WSrodek, MOrientacja) {};
void Obrot(double kat) override;
void Przesuniecie(double odleglosc, double kat) override;
int Narysuj(std::shared_ptr<drawNS::Draw3DAPI>& api) override;
 bool czy_kolizja(std::shared_ptr<InterfejsDrona> D) override;
 const Wektor<double, 3>& ZwrocSrodek()const override;
 double ZwrocPromien()const override;
};

#endif