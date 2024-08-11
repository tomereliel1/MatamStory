#include "Snail.h"
#include <string>
using std::string;

Snail::Snail(string & type) : Encounter(type){
    m_combatPower = 5;
    m_loot = 2;
    m_damage = 10;
}

