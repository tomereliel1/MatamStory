#include <string>
#include "EventFactory.h"
#include "Slime.h"
#include "Snail.h"
#include "Barlog.h"
#include "Pack.h"
#include "SolarEclipse.h"
#include "PotionsMerchant.h"
#include <memory>
#include <stdexcept>
#include <sstream>
#include <vector>

using std::string;
using std::unique_ptr;

unique_ptr<Event> EventFactory::create(string& type) const {
    if (type == "SolarEclipse"){
        unique_ptr<Event> newEvent(new SolarEclipse(type));
        return newEvent;
    } else if (type == "PotionMerchant"){
        unique_ptr<Event> newEvent(new PotionsMerchant(type));
        return newEvent;
    } else if (type == "Snail"){
        unique_ptr<Event> newEvent(new Snail(type));
        return newEvent;
    } else if (type == "Slime"){
        //unique_ptr<Event> newEvent(new Slime(type));
        //return newEvent;
    } else if (type == "Barlog"){
        //unique_ptr<Event> newEvent(new Barlog(type));
        //return newEvent;
    } else if (checkPack(type)){
        return createPack(type);
    }
    throw std::runtime_error("No such Event");
}

bool EventFactory::checkPack(std::string &type) {
    string pack = "Pack";
    for (int i = 0 ; i < 4 ; i++){
        if (pack[i] != type[i]){
            return false;
        }
    }
    return true;
}

unique_ptr<Event> EventFactory::createPack(string& type) const {
    std::vector<unique_ptr<Event>> subMonsters;
    std::istringstream iss(type);
    string word;
    iss >> word;
    int monsterNumber;
    iss >> monsterNumber;
    for (int i = 0 ; i < monsterNumber; i++){
        iss >> word;
        subMonsters.push_back(create(word));
    }
    return std::make_unique<Pack>(type ,std::move(subMonsters));
}

