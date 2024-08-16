#include "Slime.h"

using std::string;

const string SLIME_TYPE = "Slime";

const int SLIME_POWER = 12;
const int SLIME_LOOT = 5;
const int SLIME_DAMAGE = 25;

Slime::Slime() : Encounter(SLIME_TYPE) {
    m_combatPower = SLIME_POWER;
    m_loot = SLIME_LOOT;
    m_damage = SLIME_DAMAGE;
}