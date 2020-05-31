#include "../inc/PrzeszkodaProst.hh"

bool PrzeszkodaProst::czy_kolizja(std::shared_ptr<InterfejsDrona> D) {
    for (int i = 0; i < 8; ++i) {
        if ((this->WWierzcholki[i] - D->ZwrocSrodek()).dlugosc() < D->ZwrocPromien()) {
            std::cout << "Kolizja!" << endl;
                return true;
        }
    }
    return false;
}