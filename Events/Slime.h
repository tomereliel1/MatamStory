#pragma once
#include "Encounter.h"
#include <string>
using std::string;

/**
 * Slime - represents an Slime Encounter type
 */
class Slime :public Encounter{
public:
    /**
     * Constructor - creates an Slime Encounter
     */
    Slime();

    /**
     * Destructor - default destructor
     */
    ~Slime() override = default ;
};