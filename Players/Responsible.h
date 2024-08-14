#pragma once

#include "Character.h"
#include <string>

using std::string;

/**
 * Responsible - represents a responsible character type
 */
class Responsible : public Character {
public:
    /**
     * Constructor - creates a responsible character
     */
    explicit Responsible();

    /**
     * Applies the effect of the potions merchant on the player
     *
     * @param player - the player affected by the potions merchant
     * @return - the effect value, specific to the implementation
     */
    int applyPotionsMerchant(Player &player) override;

    /**
     * Destructor - default destructor
     */
    ~Responsible() override = default;
};
