#include "Magician.h"
#include "Player.h"
const string str = "Magician";
Magician::Magician(): Job(str){}

void Magician::applySolarEclipse(Player &player) {
    int currentForce=player.getForce();
    currentForce++;
    player.setForce(currentForce);
}

