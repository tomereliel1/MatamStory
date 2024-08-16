#include "Magician.h"
#include "Player.h"

const string MAGICIAN_TYPE = "Magician";
const int MAGICIAN_SOLAR_ECLIPSE_EFFECT = 1;


Magician::Magician() : Job(MAGICIAN_TYPE) {}

int Magician::applySolarEclipse(Player &player) {
    int currentForce = player.getForce();
    currentForce++;
    player.setForce(currentForce);
    return MAGICIAN_SOLAR_ECLIPSE_EFFECT;
}

