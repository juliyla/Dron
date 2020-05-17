#ifndef OBIEKT_RYSOWALNY_HH
#define OBIEKT_RYSOWALNY_HH
#include "../inc/Dr3D_gnuplot_api.hh"

class ObiektRysowalny {
protected:
    int index;
    std::shared_ptr<drawNS::Draw3DAPI> api;
public:
  virtual int Narysuj(std::shared_ptr<drawNS::Draw3DAPI> api) = 0;
  void Zmaz(){api->erase_shape(index);}
};

#endif