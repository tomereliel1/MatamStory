#include "Responsible.h"
#include "Player.h"
using std::string;
const string str = "Responsible";

Responsible::Responsible():Character(str){}

void Responsible::applyPotionsMerchant(Player &player) {

    int currentCoins = player.getCoins();
    int currentHP = player.getHealthPoints();
    int maxHP = player.getMaxHealthPoints();
    while ( currentCoins >= 5 && currentHP < maxHP ) {
        currentCoins-=5;
        currentHP+=10;
    }
    if( currentHP > maxHP ){ currentHP = maxHP; }

    player.setCoins(currentCoins);
    player.setHP(currentHP);
}


