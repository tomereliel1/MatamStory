#include "Archer.h"
const string str = "Archer";

Archer::Archer(): Job(str){}

int Archer::getCoins() const {
    return 20;
}
