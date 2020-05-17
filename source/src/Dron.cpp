#include "../inc/Dron.hh"

void Prostopadloscian::Obrot(double kat){
    for(unsigned int index=0; index < 8; ++index)
    {
        WWspolrzedne[index]=MacierzOb(kat)*(WWspolrzedne[index]-WSrodek)+WSrodek;
    }
}

void Prostopadloscian::Przesuniecie(double odleglosc){
  Wektor<double,3> W(0,odleglosc,0);

    for(unsigned int index=0; index < 8; ++index)
    {
        WWspolrzedne[index]= WWspolrzedne[index] + W;
    }
    WSrodek= WSrodek + W;
}

