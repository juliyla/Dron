#include <iostream>
#include <fstream>
#include "../inc/Dr3D_gnuplot_api.hh"
#include "../inc/Wektor.hh"
#include "../inc/MacierzOb.hh"
#include "../inc/Macierz.hh"
#include "../inc/Prostopadloscian.hh"
#include "../inc/Dron.hh"
#include "../inc/Powierzchnia.hh"
#include "../inc/ObiektRysowalny.hh"
#include "../inc/Dno.hh"
#include "../inc/Tafla.hh"
#include "../inc/PrzeszkodaProst.hh"


using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}



int main() {
	std::vector<std::shared_ptr<Przeszkoda> > kolekcja_przeszkod;
	std::vector<std::shared_ptr<Dron> > kolekcja_Dronow;
  int wybor = 0;
  double kat;
  double odleglosc;
  Wektor<double, 3> tabD[8];
  Wektor<double, 3> tabS[12];
  Wektor<double, 3> WSrodek; 
  MacierzOb MOrientacja;
  std::shared_ptr<Dron> dron;
  int c;
  std::shared_ptr<drawNS::Draw3DAPI> Obiekt(new APIGnuPlot3D(-100,100,-100,100,-100,100,100));
  Obiekt->change_ref_time_ms(0);
  ifstream plik;
  string plikD, plikS;
  cout << "Podaj plik z dronem" << endl;
  cin >> plikD;
  plik.open(plikD);
  for (int i = 0; i < 8; i++)
  {
	  plik >> tabD[i];
  };
  plik.close();
  cout << "Podaj plik z sruba" << endl;
  cin >> plikS;
  plik.open(plikS);
  for (int i = 0; i < 12; i++)
  {
	  plik >> tabS[i];
  };
  plik.close();

  shared_ptr<Tafla> tafla = make_shared<Tafla>();
  tafla->InicjalizujPowierzchnie();
  kolekcja_przeszkod.push_back(tafla);

  shared_ptr<Dno> dno = make_shared<Dno>();
  dno->InicjalizujPowierzchnie();
  kolekcja_przeszkod.push_back(dno);

  std::shared_ptr<PrzeszkodaProst> P1 = std::make_shared<PrzeszkodaProst>(20, 30, 40);
  P1->Narysuj(Obiekt);
  kolekcja_przeszkod.push_back(P1);

  std::shared_ptr<Dron> D1 = std::make_shared<Dron>(tabD, tabS, WSrodek, MOrientacja, Obiekt);
  D1->Przesuniecie(10, 90);
  int a = D1->Narysuj(Obiekt);
  kolekcja_Dronow.push_back(D1);
  kolekcja_przeszkod.push_back(D1);

  std::shared_ptr<Dron> D2 = std::make_shared<Dron>(tabD, tabS, WSrodek, MOrientacja, Obiekt);
  D2->Przesuniecie(0, 0);
  int b = D2->Narysuj(Obiekt);
  kolekcja_Dronow.push_back(D2);
  kolekcja_przeszkod.push_back(D2);
  
  while (wybor != 5){
    cout << "Menu wyboru: " << endl;
	cout << "Wybierz drona a lub b - 1" << endl;
    cout << "Przesuniecie drona    - 2" << endl;
	cout << "Obrot drona o kat     - 3" << endl;
	cout << "Statystyki            - 4" << endl;
    cout << "Zakonczenie programu  - 5" << endl;
    cout << "Twoj wybor: " << endl;
    cin >> wybor;
  
    switch(wybor) {
	case 1: {
		kolekcja_przeszkod.pop_back();
		kolekcja_przeszkod.pop_back();
		char dr;
		cin >> dr;
		if (dr == 'a') {
			dron = D1;
			c = a;
			kolekcja_przeszkod.push_back(kolekcja_Dronow[1]);
			break;
		}
		if (dr == 'b') {
			dron = D2;
			c = b;
			kolekcja_przeszkod.push_back(kolekcja_Dronow[0]);
			break;
		}
		break;
	}

	case 2: {
		cout << "Podaj odleglosc i kat: ";
		cin >> odleglosc;
		cin >> kat;
		bool kolizja = false;
		for (int i = 0; i <= odleglosc; i++) {
			for (auto elem : kolekcja_przeszkod) {
				kolizja = elem->czy_kolizja(dron);
				if (kolizja == true) {

					break;
				}


				else {
					if (odleglosc >= 1) {
						dron->Zmaz(c);
						odleglosc = odleglosc - 1;
						dron->Przesuniecie(1, kat);
						c = dron->Narysuj(Obiekt);
					}
					else if (odleglosc <= -1) {
						dron->Zmaz(c);
						odleglosc = odleglosc + 1;
						dron->Przesuniecie(-1, kat);
						c = dron->Narysuj(Obiekt);
					}
					else {
						dron->Zmaz(c);
						dron->Przesuniecie(odleglosc, kat);
						odleglosc = 0;
						c = dron->Narysuj(Obiekt);
					}
				}

				break;
			}
	case 3: {
		cout << "Podaj kat obrotu: ";
		cin >> kat;

		if (kat >= 1) {
			kat = kat - 1;
			dron->Zmaz(c);
			dron->Obrot(1);
			c = dron->Narysuj(Obiekt);
		}
		else if (kat <= -1) {
			dron->Zmaz(c);
			dron->Obrot(-1);
			kat = kat + 1;
			c = dron->Narysuj(Obiekt);
		}
		else {
			dron->Zmaz(c);
			dron->Obrot(1);
			kat = 0;
			c = dron->Narysuj(Obiekt);
		}

		break;
	}
		}}

	case 4: {
		cout << "Wektory:" << endl;
		cout << "Istniejace:" << Wektor<double, 3>::zwroc_istniejace() << endl;
		cout << "Wszystkie:" << Wektor<double, 3>::zwroc_wszystkie() << endl;
		cout << "Bryly:" << endl;
		cout << "Istniejace:" << Bryla::zwroc_istniejace() << endl;
		cout << "Wszystkie:" << Bryla::zwroc_wszystkie() << endl;
		break;
	}
    case 5: {
      cout << "Koniec dzialania programu" << endl;
      break;
    }}}  
  return 0;
}





/*
int main() {
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  int a=api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(2,0,0)); //rysuje linię pomiędzy (0,0,0) a (2,0,0), zapamiętuje id kształtu w zmiennej a 
  api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(0,0,5),"red"); //rysuje czerwoną linie pomiędzy (0,0,0) a (0,0,5)

  cout << endl << "pojawiły się 2 linie: czarna i czerwona" << endl;  
  wait4key();

  api->erase_shape(a); //usuwa kształt o id a
  cout << "czarna linia zniknęła" << endl;

  wait4key();

  api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,4,0),drawNS::Point3D(4,4,0),
	drawNS::Point3D(4,0,0),drawNS::Point3D(4,0,4)},"purple"); //rysuje fioletową łamaną
  cout << "pojawiła się fioletowa łamana" << endl;
  
  wait4key();
  api->change_ref_time_ms(1000);
  int b=api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,-4,0),drawNS::Point3D(-4,-4,0),
	drawNS::Point3D(-4,0,0),drawNS::Point3D(-4,0,-4)},"green");
  cout << "pojawiła się zielona łamana" << endl;
  
  wait4key();
  api->change_shape_color(b,"yellow");//zmienia kolor
  cout << "zmiana koloru z zielonej na żółtą" << endl;

  wait4key();
  api->change_ref_time_ms(-1);//odświerzanie sceny zmienione na opcję "tylko za pomocą metody redraw()"

  api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(0,0,0), drawNS::Point3D(0,1,0), drawNS::Point3D(1,1,0)
      },{
	drawNS::Point3D(0,0,3), drawNS::Point3D(0,1,3), drawNS::Point3D(1,2,4)       
	  }},"blue");//rysuje niebieski graniastosłup
  cout << "nie pojawiła się niebieski graniastosłup" << endl;
  
  wait4key();

  api->redraw();//odświerzenie sceny
  cout << "dopiero teraz pojawiła się niebieski graniastosłup" << endl;

  wait4key();
  api->change_ref_time_ms(0);

  api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-4,-2,-4), drawNS::Point3D(-4,0,-4), drawNS::Point3D(-4,2,-4)
	  },{
	drawNS::Point3D(-2,-2,-4), drawNS::Point3D(-2,0,-4), drawNS::Point3D(-2,2,-4)       
	  },{
	drawNS::Point3D(-0,-2,-4), drawNS::Point3D(-0,0,-3), drawNS::Point3D(-0,2,-4)       
	  },{
	drawNS::Point3D(2,-2,-4), drawNS::Point3D(2,0,-4), drawNS::Point3D(2,2,-4)       
	  },{
	drawNS::Point3D(4,-2,-4), drawNS::Point3D(4,0,-4), drawNS::Point3D(4,2,-4)       
	  }},"grey");//rysuje szarą powierzchnie
  cout << "pojawiła się szara powierzchnia" << endl;

  
  wait4key();
  
  
  //delete api;//dla zwykłych wskaźników musimy posprzątać
}
*/