#include "Responsible.h"
#include "Player.h"

using std::string;
const string RESPONSIBLE = "Responsible";

const int POTION_COST = 5;
const int POTION_EFFECT = 10;

Responsible::Responsible() : Character(RESPONSIBLE) {}

int Responsible::applyPotionsMerchant(Player &player) {
    int potionsPurchased = 0;
    int currentCoins = player.getCoins();
    int currentHP = player.getHealthPoints();
    int maxHP = player.getMaxHealthPoints();
    while (currentCoins >= POTION_COST && currentHP < maxHP) {
        currentCoins -= POTION_COST;
        currentHP += POTION_EFFECT;
        potionsPurchased++;
    }
    if (currentHP > maxHP) {
        currentHP = maxHP;
    }
    player.setCoins(currentCoins);
    player.setHP(currentHP);
    return potionsPurchased;
}


