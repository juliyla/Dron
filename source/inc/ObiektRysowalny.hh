#ifndef OBIEKT_RYSOWALNY_HH
#define OBIEKT_RYSOWALNY_HH
#include "../inc/Dr3D_gnuplot_api.hh"

class ObiektRysowalny {
protected:
    int index;
    std::shared_ptr<drawNS::Draw3DAPI> Obiekt;
public:
    ObiektRysowalny();
   ObiektRysowalny(drawNS::Draw3DAPI* Obiekt) : Obiekt(Obiekt) {}
  virtual int Narysuj(std::shared_ptr<drawNS::Draw3DAPI> api) = 0;
  void Zmaz(int index){Obiekt->erase_shape(index);}
};

#endif