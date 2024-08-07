#include "Warrior.h"

Warrior::Warrior(string &type): Job(type){}

int Warrior::getMaxHP() const {
    return 150;
}

int Warrior::getCombatPower(int force, int level) const {
    return (force * 2 + level);
}