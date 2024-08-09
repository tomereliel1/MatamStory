#include "SpecialEvent.h"
#pragma once
#include <string>
using std::string;

class PotionsMerchant : SpecialEvent {

public:
    void playEvent( Player& player) const override;

    explicit PotionsMerchant(string & type);
};
