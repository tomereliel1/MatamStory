#pragma once
#include <string>
using std::string;
class Warrior;

class Job{
protected:
    string m_type;
public:
    explicit Job(string &type);
    virtual int getMaxHP() const;
    virtual int  getCoins() const;
    virtual int getCombatPower(int force, int level) const;
    string getType() const;
};

Job::Job(string &type): m_type(type){}

int Job::getMaxHP() const{
    return 100;
}

int Job::getCoins() const{
    return 10;
}

int Job::getCombatPower(int force, int level) const {
    return force + level;
}

string Job::getType() const {
    return m_type;
}