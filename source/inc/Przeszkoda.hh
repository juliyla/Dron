#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH


#include <vector>
#include "Dron.hh"
#include "Dr3D_gnuplot_api.hh"
#include "InterfejsDrona.hh"


class Przeszkoda : public InterfejsDrona {
	
	public:
	virtual bool czy_kolizja(std::shared_ptr<InterfejsDrona> D) = 0;
};

#endif