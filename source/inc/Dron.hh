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
    Dron(): Prostopadloscian() {}
void InicjujSruby();
void InicjujDrona();
void Obrot(double kat)override;
void Przesuniecie(double odleglosc)override;
};

#endif