#pragma once
#include "Encounter.h"
#include <string>
using std::string;
class Barlog :public Encounter{
public:
    Barlog();
    void updateCombatPower() override;
    //void playEvent(Player &player) override;
};

