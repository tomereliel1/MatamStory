#include "Slime.h"
#include <string>
using std::string;

Slime::Slime(string & type) : Encounter(type){
    m_combatPower = 12;
    m_loot = 5;
    m_damage = 25;
}