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

void Warrior::playerWon(Player &player, int loot) const {
    int currentLevel = player.getLevel();
    int currentHP = player.getHealthPoints();
    int currentCoins = player.getCoins();
    currentLevel++;
    currentHP -= 10;
    currentCoins += loot;
    player.setLevel(currentLevel);
    player.setHP(currentHP);
    player.setCoins(currentCoins);
}