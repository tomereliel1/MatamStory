#pragma once
#include "Job.h"
#include <string>
using std::string;
class Warrior :public Job{
public:
    explicit Warrior();

    int getMaxHP() const override;

    int getCombatPower(int force, int level) const override;

    ~Warrior() override = default;
};
