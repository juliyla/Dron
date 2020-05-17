#ifndef BRYLA_HH
#define BRYLA_HH
#include "../inc/MacierzOb.hh"
#include "../inc/Dr3D_gnuplot_api.hh"
#include "../inc/ObiektRysowalny.hh"

class Bryla : public ObiektRysowalny { 
protected:
  Wektor<double,3> WSrodek; 
public:
 Bryla(): WSrodek(0,0,0);
};


#endif