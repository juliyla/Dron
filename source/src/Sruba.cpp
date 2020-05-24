#include "../inc/Sruba.hh"


void Sruba::ObrotSr(MacierzOb NowaMOrientacjaDr){
	MOrientacja = NowaMOrientacjaDr * MOrientacjaSr * MacierzOb(katSr,'X');
}

void Sruba::PrzesuniecieSr(Wektor<double, 3> NowyWSrodekDr) {
	WSrodek = NowyWSrodekDr + MOrientacja * WSrodekSr;
}