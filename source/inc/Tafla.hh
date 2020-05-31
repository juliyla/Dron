#ifndef TAFLA_HH
#define TAFLA_HH

#include "Powierzchnia.hh"

class Tafla : public Powierzchnia{

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
    Obiekt->change_shape_color(index,"blue");
    Obiekt->redraw();
};
    bool czy_kolizja(std::shared_ptr<InterfejsDrona> D) override {
        for (vector<drawNS::Point3D>& W : WWierzcholki){
            for (drawNS::Point3D& j : W){
                if (std::abs(j[2] - D->ZwrocSrodek()[2]) < D->ZwrocPromien() &&
                    (D->ZwrocSrodek()[0]<j[0] + D->ZwrocPromien() &&
                        D->ZwrocSrodek()[0]>j[0] - D->ZwrocPromien()) &&
                    (D->ZwrocSrodek()[1]<j[1] + D->ZwrocPromien() &&
                        D->ZwrocSrodek()[1]>j[1] - D->ZwrocPromien()))
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