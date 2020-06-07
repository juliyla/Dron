#ifndef DNO_HH
#define DNO_HH

#include "Powierzchnia.hh"

class Dno : public Powierzchnia{

public:
   void InicjalizujPowierzchnie() {
       std::vector<drawNS::Point3D> W;
    for (int i = -10; i <= 10; i+=2) {
    W.clear();
    for (int j = -10; j <= 10; j += 2) {
    W.push_back(drawNS::Point3D(i, j, 9));
    }
    WWierzcholki.push_back(W);
    } 
    Rysuj();
    Obiekt->change_shape_color(index,"yellow");
    Obiekt->redraw();
};

   bool czy_kolizja(std::shared_ptr<InterfejsDrona> D) override {
       for (vector<drawNS::Point3D>& W : WWierzcholki){
           for (drawNS::Point3D& j : W){
               if (( D->ZwrocSrodek()[2] - D->ZwrocPromien() ) < std::abs(j[2]) )
                   
               {
                   std::cout << "Kolizja!" << std::endl;

                   return true;
               }
           }

       }
       return false;


   };

};


#endif