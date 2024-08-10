#pragma once
#include "SpecialEvent.h"
#include <string>
using std::string;
class PotionsMerchant : public SpecialEvent{
public:
    explicit PotionsMerchant(string & type);
    void playEvent( Player& player) const override;
};

