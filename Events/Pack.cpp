#include "Pack.h"
#include <string>
#include <memory>
#include <vector>
using std::string;
using std::unique_ptr;
using std::vector;

const string str = "Pack";
Pack::Pack(int membersNum, vector<unique_ptr<Event>> subMonsters) : Encounter(str),
    m_membersNum(membersNum)
{
    for (std::vector<unique_ptr<Event>>::iterator it = subMonsters.begin(); it != subMonsters.end();
    ++it) {
        Encounter *encounterPtr = dynamic_cast<Encounter *>(it->release());
        if (encounterPtr) {
            unique_ptr<Encounter> encounter(encounterPtr);
            m_subMonsters.push_back(std::move(encounter));
        }
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

void Pack::playEvent(Player &player){
    if (player.getCombatPower() > m_combatPower){
        player.getJob()->playerWon(player);
    } else {
        player.playerLost(m_damage);
    }
    updateCombatPower();
}

void Pack::updateCombatPower(){
    int tempCombatPower = 0;
    for (int i = 0; i < m_membersNum ; i++){
        m_subMonsters[i]->updateCombatPower();
        tempCombatPower += m_subMonsters[i]->getCombatPower();
    }
    m_combatPower = tempCombatPower;
}