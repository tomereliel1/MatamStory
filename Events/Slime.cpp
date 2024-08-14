#include "Slime.h"

using std::string;

const string str = "Slime";

Slime::Slime() : Encounter(str) {
    m_combatPower = 12;
    m_loot = 5;
    m_damage = 25;
}