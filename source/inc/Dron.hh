#ifndef DRON_HH
#define DRON_HH

#include<iostream>
#include "Prostopadloscian.hh"
#include "InterfejsDrona.hh"

class Dron: public InterfejsDrona, public Prostopadloscian
{
    
public:
    Dron(): Prostopadloscian() {}

void Obrot(double kat)override;
void Przesuniecie(double odleglosc)override;
};

#endif