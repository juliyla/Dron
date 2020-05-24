#include "../inc/MacierzOb.hh"

MacierzOb::MacierzOb(const Macierz<double, 3>& M) : Macierz<double, 3>(M)
{
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
  if(abs(M.wyznacznik - 1) > epsilon){
    cout << "Wyznacznik rozny od 1" << endl;
    exit(1);
  }
}

MacierzOb::MacierzOb(){
   double kat=0;
    for (int i = 0; i < 3 ; ++i)
        for (int j = 0; j < 3; ++j)
            if(i==j)
                tab[i][j]=1;
            else
                tab[i][j]=0;

}

 MacierzOb::MacierzOb(double kat) {
     tab[0][0] = cos(kat * PI / 180);
     tab[0][1] = -sin(kat * PI / 180);
     tab[0][2] = 0.0;
     tab[1][0] = sin(kat * PI / 180);
     tab[1][1] = cos(kat * PI / 180);
     tab[1][2] = 0.0;
     tab[2][0] = 0.0;
     tab[2][1] = 0.0;
     tab[2][2] = 1.0;
}

 MacierzOb::MacierzOb(double kat, char os)
 {
     switch (os){
     case 'Z': {
         tab[0][0] = cos(kat * PI / 180);
         tab[0][1] = -sin(kat * PI / 180);
         tab[0][2] = 0.0;
         tab[1][0] = sin(kat * PI / 180);
         tab[1][1] = cos(kat* PI / 180);
         tab[1][2] = 0.0;
         tab[2][0] = 0.0;
         tab[2][1] = 0.0;
         tab[2][2] = 1.0;
         break;
     }
     case 'X': {
         tab[0][0] = 1.0;
         tab[0][1] = 0.0;
         tab[0][2] = 0.0;
         tab[1][0] = 0.0;
         tab[1][1] = cos(kat * PI / 180);
         tab[1][2] = -sin(kat * PI / 180);
         tab[2][0] = 0.0;
         tab[2][1] = sin(kat * PI / 180);
         tab[2][2] = cos(kat * PI / 180);
         break;
     }
     case 'Y': {
         tab[0][0] = cos(kat * PI / 180);
         tab[0][1] = 0.0;
         tab[0][2] = sin(kat * PI / 180);
         tab[1][0] = 0.0;
         tab[1][1] = 1.0;
         tab[1][2] = 0.0;
         tab[2][0] = -sin(kat * PI / 180);
         tab[2][1] = 0.0;
         tab[2][2] = cos(kat * PI / 180);
         break;
     }

     default:
         {
         tab[0][0] = cos(kat * PI / 180);
         tab[0][1] = -sin(kat * PI / 180);
         tab[0][2] = 0.0;
         tab[1][0] = sin(kat * PI / 180);
         tab[1][1] = cos(kat * PI / 180);
         tab[1][2] = 0.0;
         tab[2][0] = 0.0;
         tab[2][1] = 0.0;
         tab[2][2] = 1.0;

         break;
         };
         break;
     }
 }