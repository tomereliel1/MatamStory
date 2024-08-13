#include "Magician.h"
#include "Player.h"
const string str = "Magician";
Magician::Magician(): Job(str){}

int Magician::applySolarEclipse(Player &player) {
    int currentForce=player.getForce();
    currentForce++;
    player.setForce(currentForce);
    return 1;
}

