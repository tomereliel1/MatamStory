#pragma once
#include "Job.h"
#include <string>
using std::string;

/**
 * Magician - represents a magician job type for a player
 */
class Magician : public Job {
public:
    /**
     * Constructor - creates a magician job
     */
    explicit Magician();

    /**
     * Applies the effect of a solar eclipse on the player
     *
     * @param player - the player affected by the solar eclipse
     * @return - some effect value, specific to the magician's implementation
     */
    int applySolarEclipse(Player &player) override;

    /**
     * Destructor - default destructor
     */
    ~Magician() override = default;
};
