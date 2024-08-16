#include "Snail.h"
using std::string;

const string SNAIL_TYPE = "Snail";

const int SNAIL_POWER = 5;
const int SNAIL_LOOT = 2;
const int SNAIL_DAMAGE = 10;


Snail::Snail() : Encounter(SNAIL_TYPE){
    m_combatPower = SNAIL_POWER;
    m_loot = SNAIL_LOOT;
    m_damage = SNAIL_DAMAGE;
}

