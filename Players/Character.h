#pragma once
#include <string>
using std::string;
class Player;
class Character{
protected:
    string m_type;

public:
    explicit Character(const string& type);
    virtual string getType() const;
    virtual void applyPotionsMerchant( Player &player ) = 0;
    virtual ~Character() = default;
};