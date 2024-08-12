#include "PotionsMerchant.h"
#include "Player.h"
#include "Utilities.h"
using std::string;

const string str = "PotionMerchant";

PotionsMerchant::PotionsMerchant():SpecialEvent(str) {}

string PotionsMerchant::playEvent( Player &player) {
    int potionsPurchased = player.getCharacter()->applyPotionsMerchant(player);
    return getPotionsPurchaseMessage(player, potionsPurchased);
}

