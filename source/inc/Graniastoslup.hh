#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include "Bryla.hh"
#include "Wektor.hh"
#include "MacierzOb.hh"

class Graniastoslup : public Bryla {
protected:
	Wektor<double, 3> WWierzcholki[12];
public:
	Graniastoslup(Wektor<double, 3>* tab, Wektor<double, 3>& WSrodek, MacierzOb& MOrientacja, drawNS::APIGnuPlot3D* Obiekt);
  int Narysuj(std::shared_ptr<drawNS::Draw3DAPI> api);
};

#endif