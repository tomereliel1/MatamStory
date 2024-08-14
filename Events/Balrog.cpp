#include "Balrog.h"

using std::string;

const string str = "Balrog";

Balrog::Balrog() : Encounter(str) {
    m_combatPower = 15;
    m_loot = 100;
    m_damage = 9001;
}

void Balrog::updateCombatPower() {
    m_combatPower += 2;
}