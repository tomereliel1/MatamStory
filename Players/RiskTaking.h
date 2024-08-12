#pragma once
#include "Character.h"
#include <string>
using std::string;
class RiskTaking :public Character{
public:
    explicit RiskTaking();

    int applyPotionsMerchant(Player &player) override;

    ~RiskTaking() override = default;
};
