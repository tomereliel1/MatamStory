#pragma once
#include "Character.h"
#include <string>
using std::string;
class Responsible :public Character{
public:
    explicit Responsible();

    int applyPotionsMerchant(Player &player) override;

    ~Responsible() override = default;
};
