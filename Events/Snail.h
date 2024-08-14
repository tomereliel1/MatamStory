#pragma once

#include "Encounter.h"

using std::string;

/**
 * Snail - represents an Snail Encounter type
 */
class Snail : public Encounter {
public:
    /**
     * Constructor - creates an Snail Encounter
     */
    Snail();

    /**
     * Destructor - default destructor
     */
    ~Snail() override = default ;

};

