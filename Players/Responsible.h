#pragma once
#include "Character.h"
#include <string>
using std::string;
class Responsible :public Character{
public:
    explicit Responsible();

    void applyPotionsMerchant(Player &player) override;

    ~Responsible() override = default;
};
