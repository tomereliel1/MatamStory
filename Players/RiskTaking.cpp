#include "RiskTaking.h"
#include "Player.h"

using std::string;
const string str = "RiskTaking";

RiskTaking::RiskTaking() : Character(str) {}

int RiskTaking::applyPotionsMerchant(Player &player) {
    int potionsPurchased = 0;
    int currentCoins = player.getCoins();
    int currentHP = player.getHealthPoints();

    if (currentCoins >= 5 && currentHP < 50) {
        currentCoins -= 5;
        currentHP += 10;
        player.setCoins(currentCoins);
        player.setHP(currentHP);
        potionsPurchased++;
    }
    return potionsPurchased;
}
