#include "PotionsMerchant.h"
#include <string>
using std::string;


PotionsMerchant::PotionsMerchant(string &type):SpecialEvent(type) {}

void PotionsMerchant::playEvent( Player &player) const {

     std::shared_ptr<Character> currentCharacter = player.getCharacter();

     currentCharacter->applyPotionsMerchant(player);

}
