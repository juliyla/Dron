#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include "Bryla.hh"
#include "Wektor.hh"
#include "MacierzOb.hh"

using namespace std;
class Graniastoslup : public Bryla {
protected:
 MacierzOb MOrientacja;
 double podstawa;
 double wysokosc;
 Wektor <double,3> WWierzcholki[12];
public:
  void Wierzcholki();
  int Narysuj(std::shared_ptr<drawNS::Draw3DAPI> api)override;
  void ObrotG(double kat);
  void PrzesuniecieG(double odleglosc);
  
};

#endif