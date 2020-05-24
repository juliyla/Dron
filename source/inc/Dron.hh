#ifndef DRON_HH
#define DRON_HH

#include<iostream>
#include "Prostopadloscian.hh"
#include "InterfejsDrona.hh"
#include "Sruba.hh"

class Dron: public InterfejsDrona, public Prostopadloscian {
protected: 
Sruba sruba1; 
Sruba sruba2; 

public:
    Dron(Wektor<double, 3>* tabP, Wektor<double, 3>* tabS, Wektor<double, 3> WSrodek, MacierzOb& MOrientacja,drawNS::APIGnuPlot3D* Obiekt) : Prostopadloscian(tabP, WSrodek, MOrientacja,Obiekt), sruba1(Obiekt, tabS, WSrodek, MOrientacja), sruba2(Obiekt, tabS, WSrodek, MOrientacja) {};
void Obrot(double kat);
void Przesuniecie(double odleglosc, double kat);
int Narysuj(std::shared_ptr<drawNS::Draw3DAPI>& api);
};

#endif