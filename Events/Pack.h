#pragma once
#include "Encounter.h"
#include <string>
#include <memory>
#include <vector>
using std::unique_ptr;
using std::string;
class Pack :public Encounter{
private:
    std::vector<unique_ptr<Encounter>> m_subMonsters;
    void sumFields();
public:
    explicit Pack(string type, std::vector<unique_ptr<Event>> subMonsters);
    void playEvent( Player& player) const;
};

