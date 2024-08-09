#include "RiskTaking.h"
using std::string;

RiskTaking::RiskTaking():Character("RiskTaking"){}

void RiskTaking::applyPotionsMerchant(Player &player) {

    int currentCoins = player.getCoins();
    int currentHP = player.getHealthPoints();

    if ( currentCoins >= 5 && currentHP < 50 ) {
        currentCoins-=5;
        currentHP+=10;
        player.setCoins(currentCoins);
        player.setHP(currentHP);
    }
}
