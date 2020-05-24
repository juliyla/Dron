#ifndef DNO_HH
#define DNO_HH

#include "Powierzchnia.hh"

class Dno : public Powierzchnia{

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
    Obiekt->change_shape_color(index,"yellow");
    Obiekt->redraw();
};
};


#endif