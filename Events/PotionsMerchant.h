#pragma once
#include "SpecialEvent.h"
#include <string>
using std::string;

//Represents a SpecialEvent called PotionsMerchant
class PotionsMerchant : public SpecialEvent{
public:
    /**
     * Constructor - create a potionsMerchant typed event
     *
     */
    PotionsMerchant();

    /**
     * Plays the event - player buy potions
     *
     * @param player - the player who buy the potions
     *
     * @return - the outcome message
     */
    string playEvent( Player& player) override;

    /**
    * Destructor - default destructor
    */
    ~PotionsMerchant() override = default;
};

