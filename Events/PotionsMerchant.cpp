#include "PotionsMerchant.h"
#include "Player.h"
#include <string>
using std::string;

const string str = "PotionMerchant";

PotionsMerchant::PotionsMerchant():SpecialEvent(str) {}

void PotionsMerchant::playEvent( Player &player) {
    player.getCharacter()->applyPotionsMerchant(player);
}

