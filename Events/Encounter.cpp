#include "Encounter.h"
using std::string;

Encounter::Encounter(const string& type) : Event(type), m_combatPower(0), m_loot(0),
    m_damage(0) {}

int Encounter::getDamage() const {
    return m_damage;
}

int Encounter::getLoot() const {
    return m_loot;
}

int Encounter::getCombatPower() const {
    return m_combatPower;
}

void Encounter::playEvent(Player &player){
    if (player.getCombatPower() > m_combatPower){
        player.getJob()->playerWon(player);
    } else {
        player.playerLost(m_damage);
    }
}

void Encounter::updateCombatPower() {}