#include "../inc/Graniastoslup.hh"


Graniastoslup::Graniastoslup(Wektor<double, 3>* tab, Wektor<double, 3>& WSrodek, MacierzOb& MOrientacja, drawNS::APIGnuPlot3D* Obiekt ) : Bryla(WSrodek, MOrientacja, Obiekt)
{
    for (int i = 0; i < 12; i++)
    {
        WWierzcholki[i] = tab[i];
    }
};

int Graniastoslup::Narysuj(std::shared_ptr<drawNS::Draw3DAPI> api){
    {
        Graniastoslup pom(*this);
        for (int i = 0; i < 12; i++)
        {
            pom.WWierzcholki[i] = WSrodek + MOrientacja * WWierzcholki[i];
        }
        index = Obiekt->draw_polyhedron(vector<vector<drawNS::Point3D>>{ 
            {pom.WWierzcholki[0], pom.WWierzcholki[1], pom.WWierzcholki[2], 
             pom.WWierzcholki[3], pom.WWierzcholki[4], pom.WWierzcholki[5]}, 
            { pom.WWierzcholki[6],pom.WWierzcholki[7],pom.WWierzcholki[8],
             pom.WWierzcholki[9],pom.WWierzcholki[10],pom.WWierzcholki[11]}
        }, "red");
        Obiekt->redraw();
    }
    return index;
};

