#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Bryla.hh"
#include "Wektor.hh"
#include "MacierzOb.hh"

class Prostopadloscian : public Bryla 
{
protected:
  Wektor<double, 3> WWymiary;
std::vector < Wektor<double, 3>> WWspolrzedne;
public:
Prostopadloscian(); 
Prostopadloscian(): WWymiary{1,2,3}
    {
        WWspolrzedne.reserve(8);
        Wspolrzedne();
    }
void Wspolrzedne();
int Narysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) override;

#endif