#include "Snail.h"
#include <string>
using std::string;

const string str = "Snail";

Snail::Snail() : Encounter(str){
    m_combatPower = 5;
    m_loot = 2;
    m_damage = 10;
}

