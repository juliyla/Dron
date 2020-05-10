#ifndef BRYLA_HH
#define BRYLA_HH
#include "MacierzOb.hh"
#include "Dr3D_gnuplot_api.hh"

class Bryla
{
protected:
  MacierzOb MOrientacja;
  Wektor<double,3> WSrodek; 
public:
 Bryla(): WSrodek{0,0,0} {}
 virtual int Narysuj(std::shared_ptr<drawNS::Draw3DAPI> api)=0;

};


#endif