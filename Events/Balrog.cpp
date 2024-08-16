#include "Balrog.h"

using std::string;

const string BALROG_TYPE = "Balrog";

const int BALROG_POWER = 15;
const int BALROG_LOOT = 100;
const int BALROG_DAMAGE = 9001;

Balrog::Balrog() : Encounter(BALROG_TYPE) {
    m_combatPower = BALROG_POWER;
    m_loot = BALROG_LOOT;
    m_damage = BALROG_DAMAGE;
}

void Balrog::updateCombatPower() {
    m_combatPower += 2;
}