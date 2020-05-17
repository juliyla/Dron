#include "../inc/MacierzOb.hh"

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
}

MacierzOb::MacierzOb(){
 InicjujMacierzOb()
    kat=0;
    for (int i = 0; i < 3 ; ++i)
        for (int j = 0; j < 3; ++j)
            if(i==j)
                tab[i][j]=1;
            else
                tab[i][j]=0;

}

 MacierzOb::MacierzOb(double kat) {
  InicjujMacierzOb()
  {cos(kat*PI/180),sin(kat*PI/180),0},
  {-sin(kat*PI/180),cos(kat*PI/180), 0},
  {0,0,1}
 
}