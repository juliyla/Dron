#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Bryla.hh"
#include "Wektor.hh"
#include "MacierzOb.hh"

class Prostopadloscian : public Bryla {
protected:
     Wektor<double, 3> WWierzcholki[8];
public:
    Prostopadloscian(Wektor<double, 3>* tab, Wektor<double, 3>& WSrodek, MacierzOb& MOrientacja, drawNS::APIGnuPlot3D* Obiekt) : Bryla(WSrodek, MOrientacja, Obiekt) {};
    int Narysuj(std::shared_ptr<drawNS::Draw3DAPI> api) override;
};

#endif