#include "Warrior.h"
#include "Player.h"
const string str = "Warrior";
const bool closeRanged = true;
Warrior::Warrior(): Job(str, closeRanged){}

int Warrior::getMaxHP() const {
    return 150;
}

int Warrior::getCombatPower(int force, int level) const {
    return (force * 2 + level);
}
