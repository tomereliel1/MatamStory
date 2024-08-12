#pragma once
#include "SpecialEvent.h"
#include <string>
using std::string;
class PotionsMerchant : public SpecialEvent{
public:
    PotionsMerchant();
    void playEvent( Player& player) override;
};

