#pragma once
#include "Job.h"
#include <string>
using std::string;

/**
 * Archer - represents an archer job type for a player
 */
class Archer : public Job {
public:
    /**
     * Constructor - creates an archer job
     */
    explicit Archer();

    /**
     * Gets the amount of coins associated with the archer job
     *
     * @return - coins for the archer job
     */
    int getCoins() const override;

    /**
     * Destructor - default destructor
     */
    ~Archer() override = default;
};
