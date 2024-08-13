#pragma once
#include "Event.h"
#include <string>
using std::string;
class Encounter :public Event{
protected:
    int m_combatPower;
    int m_loot;
    int m_damage;
public:
    explicit Encounter(const string& type);
    int getDamage() const;
    int getCombatPower() const;
    int getLoot() const;
    string playEvent( Player& player) override;
    virtual void updateCombatPower();
    string getDescription() const override;
};

