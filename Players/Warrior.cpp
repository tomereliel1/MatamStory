#include "Warrior.h"
#include "Player.h"
const string str = "Warrior";
Warrior::Warrior(): Job(str){}

int Warrior::getMaxHP() const {
    return 150;
}

int Warrior::getCombatPower(int force, int level) const {
    return (force * 2 + level);
}

void Warrior::playerWon(Player &player) const {
    int currentLevel = player.getLevel();
    currentLevel++;
    player.setLevel(currentLevel);
    int currentHP = player.getHealthPoints();
    currentHP -= 10;
    player.setHP(currentHP);
}