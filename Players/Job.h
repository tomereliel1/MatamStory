#pragma once
#include <string>
using std::string;
class Player;

class Job{
protected:
    string m_type;
public:
    explicit Job(const string& type);
    virtual int getMaxHP() const;
    virtual int  getCoins() const;
    virtual int getCombatPower(int force, int level) const;
    virtual int applySolarEclipse( Player &player );
    string getType() const;
    virtual void playerWon(Player & player, int loot) const;
    virtual ~Job() = default;

};
