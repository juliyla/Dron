#include "../inc/PrzeszkodaProst.hh"

bool PrzeszkodaProst::czy_kolizja(std::shared_ptr<InterfejsDrona> D) {
    
        if (D->ZwrocSrodek()[0] > (this->WWierzcholki[0][0] - D->ZwrocPromien()) &&
            D->ZwrocSrodek()[0] > (this->WWierzcholki[1][0] + D->ZwrocPromien()) &&
            D->ZwrocSrodek()[1] > (this->WWierzcholki[0][1] - D->ZwrocPromien()) &&
            D->ZwrocSrodek()[1] > (this->WWierzcholki[3][1] + D->ZwrocPromien()) &&
            D->ZwrocSrodek()[2] > (this->WWierzcholki[0][2] - D->ZwrocPromien()) &&
            D->ZwrocSrodek()[2] > (this->WWierzcholki[4][2] + D->ZwrocPromien()) ) {
            std::cout << "Kolizja!" << endl;
                return true;
        }
    
    return false;
}