#pragma once

#include <string>

using std::string;

/**
 * Forward declaration of the Player class
 */
class Player;

/**
 * Character - represents a character type that a player can have
 */
class Character {
protected:
    // m_type - the type of the character
    string m_type;

public:
    /**
     * Constructor - creates a character with a specific type
     *
     * @param type - the type of the character
     */
    explicit Character(const string &type);

    /**
     * Gets the type of the character
     *
     * @return - the type of the character
     */
    virtual string getType() const;

    /**
     * Applies the effect of the potions merchant on the player
     *
     * @param player - the player affected by the potions merchant
     * @return - some effect value, specific to the implementation
     */
    virtual int applyPotionsMerchant(Player &player) = 0;

    /**
     * Destructor - default destructor for the Character class
     */
    virtual ~Character() = default;
};
