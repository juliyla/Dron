#ifndef BRYLA_HH
#define BRYLA_HH
#include "../inc/MacierzOb.hh"
#include "../inc/Dr3D_gnuplot_api.hh"
#include "../inc/ObiektRysowalny.hh"

class Bryla : public ObiektRysowalny { 
protected:
  Wektor<double,3> WSrodek; 
  MacierzOb MOrientacja;
public:
    int istniejace = 0;
    int usuniete = 0;
  int zwroc_istniejace() { return istniejace; }
  int zwroc_usuniete() { return usuniete; }
  int zwroc_wszystkie() { return istniejace + usuniete; }
    Bryla() { istniejace++; }
	Bryla(Wektor<double, 3>& WSrodek, MacierzOb& MOrientacja, drawNS::APIGnuPlot3D* Obiekt): ObiektRysowalny(Obiekt), WSrodek(WSrodek), MOrientacja(MOrientacja){ istniejace++; }
    ~Bryla() {
        usuniete++; istniejace--;
    }
};


#endif