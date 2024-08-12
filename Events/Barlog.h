#pragma once
#include "Encounter.h"
#include <string>
using std::string;
class Barlog :public Encounter{
private:
    void updateCombatPower() override;
public:
    Barlog();
    void playEvent(Player &player) override;
};

