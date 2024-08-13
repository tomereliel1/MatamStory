#include "Barlog.h"
#include <string>
using std::string;

const string str = "Barlog";

Barlog::Barlog() : Encounter(str){
    m_combatPower = 15;
    m_loot = 100;
    m_damage = 9001;
}

/*
void Barlog::playEvent(Player &player){
    if (player.getCombatPower() > m_combatPower){
        player.getJob()->playerWon(player);
    } else {
        player.playerLost(m_damage);
    }
    updateCombatPower();
}*/

void Barlog::updateCombatPower(){
    m_combatPower += 2;
}