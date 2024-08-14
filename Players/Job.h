#pragma once
#include <string>
using std::string;
class Player;

class Job{
protected:
    string m_type;
    bool m_closeRanged;
public:
    explicit Job(const string& type, bool closeRanged = false);
    virtual int getMaxHP() const;
    virtual int  getCoins() const;
    virtual int getCombatPower(int force, int level) const;
    virtual int applySolarEclipse( Player &player );
    string getType() const;
    void playerWon(Player & player, int loot) const;
    virtual ~Job() = default;
    void playerLost(Player& player, int damage);

};
