#include "MacierzOb.hh"

void InicjujMacierzOb(){
  double epsilon = 0.000000001;
  if(abs(tab[0] * tab[1]) > epsilon){
    cout << "Macierz nie jest ortogonalna" << endl;
    exit(1);
  }
  if(abs(tab[1] * tab[2]) > epsilon){
    cout << "Macierz nie jest ortogonalna" << endl;
    exit(1);
  }
  if(abs(tab[0] * tab[2]) > epsilon){
    cout << "Macierz nie jest ortogonalna" << endl;
    exit(1);
  }
  if(abs((*this).wyznacznik - 1) > epsilon){
    cout << "Wyznacznik rozny od 1" << endl;
    exit(1);
  }

 Macierz<double,3> {
  {cos(m_kat*PI/180),sin(m_kat*PI/180),0},
  {-sin(m_kat*PI/180),cos(m_kat*PI/180), 0},
  {0,0,1}
 
};