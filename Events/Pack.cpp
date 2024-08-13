#include "Pack.h"
#include "Utilities.h"
#include <string>
#include <memory>
#include <vector>
using std::string;
using std::unique_ptr;
using std::vector;

Pack::Pack(int membersNum, vector<unique_ptr<Encounter>> subMonsters) :
Encounter( "Pack of " +std::to_string(membersNum) + " members" ),
    m_membersNum(membersNum)
{
    for (std::vector<unique_ptr<Encounter>>::iterator it = subMonsters.begin(); it != subMonsters.end();
    ++it) {
        unique_ptr<Encounter> encounter(it->release());
        m_subMonsters.push_back(std::move(encounter));
    }
    sumFields();
}

void Pack::sumFields() {
    vector<unique_ptr<Encounter>>::const_iterator beginIterator = m_subMonsters.begin();
    m_damage = 0;
    m_loot = 0;
    m_combatPower = 0;
    for (const std::unique_ptr<Encounter>& monster : m_subMonsters) {
        m_combatPower += monster->getCombatPower();
        m_damage += monster->getDamage();
        m_loot += monster->getLoot();
    }
}
/*
string Pack::playEvent(Player &player){
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
}*/

void Pack::updateCombatPower(){
    int tempCombatPower = 0;
    for (int i = 0; i < m_membersNum ; i++){
        m_subMonsters[i]->updateCombatPower();
        tempCombatPower += m_subMonsters[i]->getCombatPower();
    }
    m_combatPower = tempCombatPower;
}