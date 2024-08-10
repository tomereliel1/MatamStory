#include "PotionsMerchant.h"

#include <string>
using std::string;


PotionsMerchant::PotionsMerchant(string & type):SpecialEvent(type) {}

void PotionsMerchant::playEvent( Player &player) const {
    player.getCharacter()->applyPotionsMerchant(player);
}

