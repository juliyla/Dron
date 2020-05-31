#ifndef INTERFEJS_DRONA
#define INTERFEJS_DRONA

#include <math.h>
#include "MacierzOb.hh"
#include "Wektor.hh"
#include "Dron.hh"
#include "Powierzchnia.hh"

class InterfejsDrona {
public:
	virtual void Obrot(double kat)=0;
	virtual void Przesuniecie(double odleglosc, double kat)=0;
	virtual const Wektor<double, 3>& ZwrocSrodek()const = 0;
	virtual double ZwrocPromien()const = 0;
};

  
#endif