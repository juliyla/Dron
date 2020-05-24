#ifndef TAFLA_HH
#define TAFLA_HH

#include "Powierzchnia.hh"

class Tafla : public Powierzchnia{

public:
    void InicjalizujPowierzchnie() {
    for (int i = -10; i <= 10; i+=2) {
    std::vector<drawNS::Point3D> W;
    for (int j = -10; j <= 10; j += 2) {
    W.push_back(drawNS::Point3D(i, j, 9));
    }
    WWierzcholki.push_back(W);
    } 
    Rysuj();
    Obiekt->change_shape_color(index,"blue");
    Obiekt->redraw();
};
};


#endif