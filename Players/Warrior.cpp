#include "Warrior.h"
#include "Player.h"

const string WARRIOR_TYPE = "Warrior";

const bool CLOSED_RANGED = true;

const int WARRIOR_DEFAULT_HP = 150;
const int WARRIOR_FORCE_MULTYPLY = 2;



Warrior::Warrior() : Job(WARRIOR_TYPE, CLOSED_RANGED) {}

int Warrior::getMaxHP() const {
    return WARRIOR_DEFAULT_HP;
}

int Warrior::getCombatPower(int force, int level) const {
    return (force * WARRIOR_FORCE_MULTYPLY + level);
}
