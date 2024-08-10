#include "Magician.h"

Magician::Magician(string& type): Job(type){}

void Magician::applySolarEclipse(Player &player) {
    int currentForce=player.getForce();
    currentForce++;
    player.setForce(currentForce);
}

