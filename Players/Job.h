#pragma once
#include <string>
using std::string;

class Job{
protected:
    string m_type;
public:
    explicit Job(string &type);
    virtual int getMaxHP() const;
    virtual int  getCoins() const;
    virtual int getCombatPower(int force, int level) const;
    string getType() const;

    virtual ~Job() = default;
};
