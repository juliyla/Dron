#include "../inc/Graniastoslup.hh"

void Graniastoslup::WWierzcholki(){
    Wektor <double,3> Wpodstawa(podstawa/2,0,0);
    Wektor <double,3> Wdlugosc(0,dlugosc/2,0);
    Wektor <double,3> Wwysokosc(0,0,(podstawa*sqrt(3))/2);
    WWWierzcholki[0]=Wsrodek+MOrientacja*((Wpodstawa+Wdlugosc+Wwysokosc)*(-1));
    WWWierzcholki[1]=Wsrodek+MOrientacja*(Wpodstawa-Wdlugosc-Wwysokosc);
    WWWierzcholki[2]=Wsrodek+MOrientacja*(Wpodstawa*2-Wdlugosc);
    WWWierzcholki[3]=Wsrodek+MOrientacja*(Wpodstawa-Wdlugosc+Wwysokosc);
    WWWierzcholki[4]=Wsrodek+MOrientacja*(Wwysokosc-Wpodstawa-Wdlugosc);
    WWWierzcholki[5]=Wsrodek+MOrientacja*(Wpodstawa*(-2)-Wdlugosc);
    WWWierzcholki[6]=Wsrodek+MOrientacja*(Wdlugosc-Wpodstawa-Wwysokosc);
    WWWierzcholki[7]=Wsrodek+MOrientacja*(Wpodstawa+Wdlugosc-Wwysokosc);
    WWWierzcholki[8]=Wsrodek+MOrientacja*(Wpodstawa*2+Wdlugosc);
    WWWierzcholki[9]=Wsrodek+MOrientacja*(Wpodstawa+Wdlugosc+Wwysokosc);
    WWWierzcholki[10]=Wsrodek+MOrientacja*(Wwysokosc+Wdlugosc-Wpodstawa);
    WWWierzcholki[11]=Wsrodek+MOrientacja*(Wpodstawa*(-2)+Wdlugosc);
}
int Graniastoslup::Narysuj(){
  WWierzcholki();
int index=api->draw_polyhedron(vector<vector<Point3D>> {{                                         
        drawNS::Point3D(WWierzcholki[0][0],WWierzcholki[0][1],WWierzcholki[0][2]),
	drawNS::Point3D(WWierzcholki[1][0],WWierzcholki[1][1],WWierzcholki[1][2]),
	drawNS::Point3D(WWierzcholki[2][0],WWierzcholki[2][1],WWierzcholki[2][2]),
	drawNS::Point3D(WWierzcholki[3][0],WWierzcholki[3][1],WWierzcholki[3][2]),
	drawNS::Point3D(WWierzcholki[4][0],WWierzcholki[4][1],WWierzcholki[4][2]),
	drawNS::Point3D(WWierzcholki[5][0],WWierzcholki[5][1],WWierzcholki[5][2])             
      },{                                                                                  
        drawNS::Point3D(WWierzcholki[6][0],WWierzcholki[6][1],WWierzcholki[6][2]),
	drawNS::Point3D(WWierzcholki[7][0],WWierzcholki[7][1],WWierzcholki[7][2]),
	drawNS::Point3D(WWierzcholki[8][0],WWierzcholki[8][1],WWierzcholki[8][2]),
	drawNS::Point3D(WWierzcholki[9][0],WWierzcholki[9][1],WWierzcholki[9][2]),
	drawNS::Point3D(WWierzcholki[10][0],WWierzcholki[10][1],WWierzcholki[10][2]),
	drawNS::Point3D(WWierzcholki[11][0],WWierzcholki[11][1],WWierzcholki[11][2])            
          }},"red");
	return index;
}

void Graniastoslup::ObrotG(double kat){
     for(unsigned int index=0; index < 12; ++index)
    {
        WWierzcholki[index]=MacierzOb(kat)*(WWierzcholki[index]-WSrodek)+WSrodek;
    }
}

void Graniastoslup::PrzesuniecieG(double odleglosc){
  Wektor<double,3> W(0,odleglosc,0);

    for(unsigned int index=0; index < 8; ++index)
    {
        WWierzcholki[index]= WWierzcholki[index] + W;
    }
    WSrodek= WSrodek + W;
}