#include "Prostopadloscian.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::vector;

Prostopadloscian::Prostopadloscian() {}

void Prostopadloscian::Wspolrzedne() {
  WWspolrzedne[0] = WSrodek;
  WWspolrzedne[1] = WSrodek - WWymiary[0]/2;
  WWspolrzedne[2] = WSrodek - WWymiary[0]/2 - WWymiary[1]/2,;
  WWspolrzedne[3] = WSrodek - WWymiary[1]/2;
  WWspolrzedne[4] = WSrodek - WWymiary[2]/2;
  WWspolrzedne[5] = WSrodek - WWymiary[0]/2 - WWymiary[2]/2;
  WWspolrzedne[6] = WSrodek - WWymiary[0]/2 - WWymiary[1]/2 - WWymiary[2]/2;
  WWspolrzedne[7] = WSrodek - WWymiary[1]/2 - WWymiary[2]/2;
}

int Narysuj(std::shared_ptr<drawNS::Draw3DAPI> & api){
 int tmp=api->draw_polyhedron(vector<vector<Point3D>>{{
            drawNS::Point3D(WWspolrzedne[0][0],WWspolrzedne[0][1],WWspolrzedne[0][2]),
            drawNS::Point3D(WWspolrzedne[1][0],WWspolrzedne[1][1],WWspolrzedne[1][2]),
            drawNS::Point3D(WWspolrzedne[3][0],WWspolrzedne[3][1],WWspolrzedne[3][2]),
            drawNS::Point3D(WWspolrzedne[2][0],WWspolrzedne[2][1],WWspolrzedne[2][2])
        },{   
            drawNS::Point3D(WWspolrzedne[4][0],WWspolrzedne[4][1],WWspolrzedne[4][2]),
            drawNS::Point3D(WWspolrzedne[5][0],WWspolrzedne[5][1],WWspolrzedne[5][2]),
            drawNS::Point3D(WWspolrzedne[7][0],WWspolrzedne[7][1],WWspolrzedne[7][2]),
            drawNS::Point3D(WWspolrzedne[6][0],WWspolrzedne[6][1],WWspolrzedne[6][2])
	    }
      }, "purple");

    return tmp;

}
