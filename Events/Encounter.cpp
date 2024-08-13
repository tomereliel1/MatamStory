#include "Encounter.h"
#include "Utilities.h"
#include <iostream>
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

string Encounter::playEvent(Player &player){
    string message;
    if (player.getCombatPower() > m_combatPower){
        player.getJob()->playerWon(player, m_loot);
        message = getEncounterWonMessage(player, m_loot);
    } else {
        player.playerLost(m_damage);
        message = getEncounterLostMessage(player, m_damage);
    }
    updateCombatPower();
    return message;
}

void Encounter::updateCombatPower() {}

string Encounter::getDescription() const {
    string description = m_type + " (power " + std::to_string(m_combatPower) + ", loot " +
            std::to_string(m_loot) + ", damage " + std::to_string(m_damage) + ")";
    return description;
}