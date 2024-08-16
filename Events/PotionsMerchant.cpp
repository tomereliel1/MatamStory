#include "PotionsMerchant.h"
#include "Player.h"
#include "Utilities.h"

using std::string;

const string POTIONS_MERCHANT_TYPE = "PotionsMerchant";

PotionsMerchant::PotionsMerchant() : SpecialEvent(POTIONS_MERCHANT_TYPE) {}

string PotionsMerchant::playEvent(Player &player) {
    int potionsPurchased = player.getCharacter()->applyPotionsMerchant(player);
    return getPotionsPurchaseMessage(player, potionsPurchased);
}

