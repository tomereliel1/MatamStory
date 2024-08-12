#pragma once
#include "SpecialEvent.h"
#include <string>
using std::string;
class PotionsMerchant : public SpecialEvent{
public:
    PotionsMerchant();
    string playEvent( Player& player) override;
};

