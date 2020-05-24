#ifndef SRUBA_HH
#define SRUBA_HH

#include "Graniastoslup.hh"

class Sruba: public Graniastoslup {
 protected:
	MacierzOb MOrientacjaSr;
	Wektor<double, 3> WSrodekSr;
	double katSr;

public:
Sruba(Wektor<double, 3>* tab, Wektor<double, 3> WSrodek, MacierzOb& MOrientacja, drawNS::APIGnuPlot3D* Obiekt) : Graniastoslup(tab, WSrodek, MOrientacja, Obiekt), MOrientacjaSr() {};
void ObrotSr(MacierzOb NowaMOrientacjaDr);
void PrzesuniecieSr(Wektor<double, 3> NowyWSrodekDr);
};

#endif