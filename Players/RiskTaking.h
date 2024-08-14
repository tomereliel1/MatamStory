#pragma once

#include "Character.h"
#include <string>

using std::string;

/**
 * RiskTaking - represents a risk-taking character type
 */
class RiskTaking : public Character {
public:
    /**
     * Constructor - creates a risk-taking character
     */
    explicit RiskTaking();

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
    ~RiskTaking() override = default;
};
