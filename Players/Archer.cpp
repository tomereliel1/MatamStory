#include "Archer.h"

Archer::Archer(string& type): Job(type){}

int Archer::getCoins() const {
    return 20;
}
