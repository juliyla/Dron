#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH


#include <vector>
#include "Dron.hh"
#include "Dr3D_gnuplot_api.hh"
#include "InterfejsDrona.hh"


class Przeszkoda : public InterfejsDrona {
	std::vector<std::shared_ptr<Przeszkoda> > kolekcja_przeszkod;
	std::vector<std::shared_ptr<Dron> > kolekcja_Dronow;
	public:
	virtual bool czy_kolizja(std::shared_ptr<InterfejsDrona> D) = 0;
};

#endif