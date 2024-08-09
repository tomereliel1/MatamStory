#pragma once
#include <string>
#include "Player.h"
using std::string;

class Job{
protected:
    string m_type;
public:
    explicit Job(string type);
    virtual int getMaxHP() const;
    virtual int  getCoins() const;
    virtual int getCombatPower(int force, int level) const;
    virtual void applySolarEclipe( Player &player );
    string getType() const;

    virtual ~Job() = default;
};
