#ifndef MACIERZ_OB
#define MACIERZ_OB

#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Wektor.hh"
#include "Macierz.hh"

#define PI 3.14159265

class MacierzOb: public Macierz<double,3> {
public:
MacierzOb();
MacierzOb(double kat);
MacierzOb(double kat, char os);
MacierzOb(const Macierz<double, 3>& M);
};



#endif