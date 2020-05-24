#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH
#include "ObiektRysowalny.hh"

class Powierzchnia : public ObiektRysowalny {
protected:
    std::vector<std::vector<drawNS::Point3D>> WWierzcholki;
public:
    virtual void InicjalizujPowierzchnie()=0;
    void Rysuj() {
 index=Obiekt->draw_surface(WWierzcholki, "blue");
};

};


#endif