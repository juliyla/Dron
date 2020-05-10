#include "Dron.hh"

void Prostopadloscian::Obrot(double kat){
 MOrientacja=MacierzOb{kat};
    for(unsigned int index=0; index < 8; ++index)
    {
        WWspolrzedne[index]=MOrientacja*(WWspolrzedne[index]-WSrodek)+WSrodek;
    }
}

void Prostopadloscian::Przesunicie(Wektor<double,3> W){
    for(unsigned int index=0; index < 8; ++index)
    {
        WWspolrzedne[index]= WWspolrzedne[index] + W;
    }
    WSrodek= WSrodek + W;
}