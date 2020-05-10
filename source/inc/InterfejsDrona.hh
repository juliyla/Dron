#ifndef INTERFEJS_DRONA
#define INTERFEJS_DRONA

#include <math.h>
#include "MacierzOb.hh"
#include "Wektor.hh"

class InterfejsDrona {
public:
  virtual void Obrot(double kat) = 0;
  virtual void Przesuniecie(double odleglosc) = 0;

};

  
#endif