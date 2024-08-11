#include "Barlog.h"
#include <string>
using std::string;

Barlog::Barlog(string& type) : Encounter(type){
    m_combatPower = 15;
    m_loot = 100;
    m_damage = 9001;
}