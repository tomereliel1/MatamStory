#include <string>
#include "EventFactory.h"
#include "Slime.h"
#include "Snail.h"
#include "Balrog.h"
#include "Pack.h"
#include "SolarEclipse.h"
#include "PotionsMerchant.h"
#include <memory>
#include <stdexcept>
#include <vector>
#include <iostream>

using std::string;
using std::unique_ptr;

const string BALROG_TYPE = "Balrog";
const string SNAIL_TYPE = "Snail";
const string SLIME_TYPE = "Slime";
const string PACK_TYPE = "Pack";
const string SOLAR_ECLIPSE_TYPE = "SolarEclipse";
const string POTIONS_MERCHANT_TYPE = "PotionsMerchant";
const string INVALID_FILE = "Invalid Events File";

const int MIN_NUMBER_IN_PACK = 2;

EventFactory::EventFactory() {
    m_creators[SOLAR_ECLIPSE_TYPE] = []() { return std::make_unique<SolarEclipse>(); };
    m_creators[POTIONS_MERCHANT_TYPE] = []() { return std::make_unique<PotionsMerchant>(); };
    m_creators[SNAIL_TYPE] = []() { return std::make_unique<Snail>(); };
    m_creators[SLIME_TYPE] = []() { return std::make_unique<Slime>(); };
    m_creators[BALROG_TYPE] = []() { return std::make_unique<Balrog>(); };
}

unique_ptr<Event> EventFactory::create(std::istream &file) const {
    std::string word;
    file >> word;
    if (word == PACK_TYPE) {
        return createPack(file);
    }
    else if (m_creators.find(word) != m_creators.end()) {
        return m_creators.find(word)->second();
    }
    else {
        throw std::runtime_error(INVALID_FILE);
    }
}

unique_ptr<Event> EventFactory::createPack(std::istream &file) const {
    std::vector<unique_ptr<Encounter>> subMonsters;
    int monsterNumber;
    file >> monsterNumber;
    if (file.fail() || monsterNumber < MIN_NUMBER_IN_PACK) {
        throw std::runtime_error(INVALID_FILE);
    }
    string word;
    for (int i = 0; i < monsterNumber; i++) {
        unique_ptr<Event> event = create(file);
        if (Encounter *encounter = dynamic_cast<Encounter *>(event.get())) {
            subMonsters.push_back(std::unique_ptr<Encounter>(encounter));
            event.release();
        }
        else {
            throw std::runtime_error(INVALID_FILE);
        }
    }
    return std::make_unique<Pack>(monsterNumber, std::move(subMonsters));
}

