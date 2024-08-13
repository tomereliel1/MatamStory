#pragma once
#include "Encounter.h"
#include <string>
using std::string;
class Balrog : public Encounter{
public:
    Balrog();
    void updateCombatPower() override;
    //void playEvent(Player &player) override;
};

