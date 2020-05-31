#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH
#include "ObiektRysowalny.hh"
#include "InterfejsDrona.hh"
#include "Dron.hh"

class Powierzchnia : public ObiektRysowalny, public Przeszkoda {
protected:
    std::vector<std::vector<drawNS::Point3D>> WWierzcholki;
public:
    virtual void InicjalizujPowierzchnie()=0;
    void Rysuj() {
 index=Obiekt->draw_surface(WWierzcholki, "blue");
};

};


#endif