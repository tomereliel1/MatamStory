#include "RiskTaking.h"
#include "Player.h"

using std::string;
const string RISK_TAKING_TYPE = "RiskTaking";

const int POTION_COST = 5;
const int POTION_EFFECT = 10;
const int HP_AMOUNT = 50;

RiskTaking::RiskTaking() : Character(RISK_TAKING_TYPE) {}

int RiskTaking::applyPotionsMerchant(Player &player) {
    int potionsPurchased = 0;
    int currentCoins = player.getCoins();
    int currentHP = player.getHealthPoints();

    if (currentCoins >= POTION_COST && currentHP < HP_AMOUNT) {
        currentCoins -= POTION_COST;
        currentHP += POTION_EFFECT;
        player.setCoins(currentCoins);
        player.setHP(currentHP);
        potionsPurchased++;
    }
    return potionsPurchased;
}
