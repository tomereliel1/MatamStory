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
#include <iostream>
using std::string;
using std::unique_ptr;

EventFactory::EventFactory() {
    m_creators["SolarEclipse"] = []() { return std::make_unique<SolarEclipse>(); };
    m_creators["PotionsMerchant"] = []() { return std::make_unique<PotionsMerchant>(); };
    m_creators["Snail"] = []() { return std::make_unique<Snail>(); };
    m_creators["Slime"] = []() { return std::make_unique<Slime>(); };
    m_creators["Barlog"] = []() { return std::make_unique<Barlog>(); };
}

unique_ptr<Event> EventFactory::create(std::istream &file) const {
    std::string word;
    file >> word;
    if (word == "Pack"){
        return createPack(file);
    } else if (m_creators.find(word) != m_creators.end()){
        return m_creators.find(word)->second();
    } else {
        throw std::runtime_error("Invalid Event File");
    }
}

unique_ptr<Event> EventFactory::createPack(std::istream &file) const {
    std::vector<unique_ptr<Encounter>> subMonsters;
    int monsterNumber;
    file >> monsterNumber;
    string  word;
    for (int i = 0 ; i < monsterNumber; i++){
        unique_ptr<Event> event = create(file);
        if (Encounter* encounter = dynamic_cast<Encounter*>(event.get())){
            subMonsters.push_back(std::unique_ptr<Encounter>(encounter));
            event.release();
        } else {
            throw std::runtime_error("Invalid Event File");
        }
    }
    return std::make_unique<Pack>(monsterNumber, std::move(subMonsters));
}

