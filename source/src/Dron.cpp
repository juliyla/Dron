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

int Dron:: Narysuj(std::shared_ptr<drawNS::Draw3DAPI>& api) {
	Prostopadloscian::Narysuj(api);
	sruba1.Narysuj(api);
	sruba2.Narysuj(api);
	return index;
}

const Wektor<double, 3>& Dron::ZwrocSrodek()const {
	return this->WSrodek;
}


double Dron::ZwrocPromien()const {
	return this->promien;
}


bool Dron::czy_kolizja(std::shared_ptr<InterfejsDrona> D) {
        if ((this->WSrodek - D->ZwrocSrodek()).dlugosc() < (this->ZwrocPromien() + D->ZwrocPromien())) {
            std::cout << "Kolizja!" << endl;
            return true;
       }
		else
    return false;
}