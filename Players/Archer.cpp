#include "Archer.h"

const string ARCHER_TYPE = "Archer";
const int ARCHER_DEFAULT_COINS = 20;

Archer::Archer() : Job(ARCHER_TYPE) {}

int Archer::getCoins() const {
    return ARCHER_DEFAULT_COINS;
}
