#include "Magician.h"

Magician::Magician(string& type): Job(type){}

void Magician::applySolarEclipe(Player &player) {
    int currentForce=player.getForce();
    currentForce++;
    player.setForce(currentForce);
}

