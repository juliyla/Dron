#include "../inc/Wektor.hh"
#include "../inc/rozmiar.h"
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/*Konstruktory*/

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar>::Wektor()
{
  for (int i=0; i<ROZMIAR; i++){
  this->tab[i] = 0;}
  istniejace++;
}
template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar>::Wektor(Typ tab[])
{   
    for(int i=0; i<ROZMIAR; i++)
    {
        this->tab[i] = tab[i];
    }
    istniejace++;
}
template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar>::Wektor(Typ x, Typ y, Typ z)
{
    tab[0] = x;
    tab[1] = y;
    tab[2] = z;
    istniejace++;
}

/*Operacje matematyczne*/

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> Wektor<Typ, Rozmiar>::operator + (const Wektor<Typ, Rozmiar> &W2) const {
  Wektor<Typ, Rozmiar>  Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = tab[i] + W2[i];
  return Wynik;
} 

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> Wektor<Typ, Rozmiar>::operator - (const Wektor<Typ, Rozmiar> &W2) const {
  Wektor<Typ, Rozmiar>  Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = tab[i] - W2[i];
  return Wynik;
} 

template<typename Typ, int Rozmiar>    
Typ Wektor<Typ, Rozmiar>::operator * (const Wektor<Typ, Rozmiar> &W2) const {
  Typ Wynik = 0;
  for (int i=0; i<ROZMIAR; i++)
    Wynik += tab[i] * W2[i];
  return Wynik;
}

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> Wektor<Typ, Rozmiar>::operator * (double l2) const{
  Wektor<Typ, Rozmiar>  Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = tab[i] * l2;
  return Wynik;
}


template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> Wektor<Typ, Rozmiar>::operator / (double l2) const{
  Wektor<Typ, Rozmiar>  Wynik;
  if(l2 == 0){
        std::cerr << "Nie wolno dzielic przez zero!" << std::endl;
        exit(1);
    }else 
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = tab[i] / l2;
  return Wynik;
}
template<typename Typ, int Rozmiar>
double Wektor<Typ, Rozmiar>::dlugosc() const {
    double l = 0;
    for (int i = 0; i < ROZMIAR; i++)
        l = l + (tab[i] * tab[i]);
    l = sqrt(l);
    return l;
}


/*Operatory porownania*/

template <typename Typ, int Rozmiar>
bool Wektor<Typ, Rozmiar>::operator == (const Wektor<Typ, Rozmiar> &W2) const{
  
  for(int i = 0; i<ROZMIAR; i++){
    if(this->tab[i]!=W2[i]){
      return false;
    }
  }
  return true;
}

template <typename Typ, int Rozmiar>
bool Wektor<Typ, Rozmiar>::operator != (const Wektor<Typ, Rozmiar> &W2) const{
 
  for(int i = 0; i<ROZMIAR; i++){
    if(this->tab[i]==W2[i]){
      return false;
    }
  }
  return true;
}

/*Analog set i get*/

template <typename Typ, int Rozmiar>
const Typ & Wektor<Typ, Rozmiar>::operator[] (int index) const{
    if (index < 0 || index >= ROZMIAR){
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    return tab[index];
  }
template <typename Typ, int Rozmiar>
Typ & Wektor<Typ, Rozmiar>::operator[] (int index){
    if (index < 0 || index >= ROZMIAR){
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    return tab[index];
  }

/*Operatory wczytywania i wyswietlania*/

template <typename Typ, int Rozmiar>
ostream & operator << (ostream &strm, const Wektor<Typ, Rozmiar> &W) {
  for (int i=0; i<ROZMIAR; i++)
    strm << W[i] << "  ";
  return strm;
}

template <typename Typ, int Rozmiar>
istream & operator >> (istream &strm, Wektor<Typ, Rozmiar> &W) {
  for (int i=0; i<ROZMIAR; i++)
    strm >> W[i];
  return strm;
}

template class Wektor<double, 3>;
template istream& operator >> (istream &strm, Wektor<double, 3> &Wek);
template ostream& operator << (ostream &strm, const Wektor<double, 3> &Wek);
