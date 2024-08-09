#include "Responsible.h"
using std::string;

Responsible::Responsible():Character("Responsible"){}

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


