#pragma once
#include "Character.h"
#include <string>
using std::string;
class RiskTaking :public Character{
public:
    explicit RiskTaking();

    void applyPotionsMerchant(Player &player) override;

    ~RiskTaking() override = default;
};
