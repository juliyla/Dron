#include "../inc/Dron.hh"

void Dron::Obrot(double kat){
   MOrientacja = MOrientacja * MacierzOb(kat);
   sruba1.ObrotSr(MOrientacja);
   sruba2.ObrotSr(MOrientacja);
}

void Dron::Przesuniecie(double odleglosc, double kat){
  Wektor<double,3> W(odleglosc,0,0);

  WSrodek = WSrodek + MOrientacja * MacierzOb(kat, 'Y') * W;

  sruba1.PrzesuniecieSr(WSrodek);
  sruba2.PrzesuniecieSr(WSrodek);
}

void Dron:: Narysuj(std::shared_ptr<drawNS::Draw3DAPI>& api) {
	Prostopadloscian::Narysuj(api);
	sruba1.Narysuj(api);
	sruba2.Narysuj(api);
}
