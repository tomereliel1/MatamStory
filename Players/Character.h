#pragma once
#include "Player.h"
#include <string>
using std::string;
class Character{
protected:
    string m_type;

public:
    explicit Character(string type);
    virtual string getType() const;
    virtual void applyPotionsMerchant( Player &player ) = 0;
    virtual ~Character() = default;
};