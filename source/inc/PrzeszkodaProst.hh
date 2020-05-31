#ifndef PRZESZKODAPROST_HH
#define PRZESZKODAPROST_HH

#include "Dron.hh"
#include "Dr3D_gnuplot_api.hh"
#include "InterfejsDrona.hh"
#include "Przeszkoda.hh"

class PrzeszkodaProst : public Przeszkoda, public Prostopadloscian {
public:
	bool czy_kolizja(std::shared_ptr<InterfejsDrona> D) override;
};

#endif