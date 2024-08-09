#include "Warrior.h"

Warrior::Warrior(): Job("Warrior"){}

int Warrior::getMaxHP() const {
    return 150;
}

int Warrior::getCombatPower(int force, int level) const {
    return (force * 2 + level);
}