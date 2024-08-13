#pragma once
#include "Encounter.h"
#include <string>
#include <memory>
#include <vector>
using std::unique_ptr;
using std::string;
class Pack :public Encounter{
private:
    int m_membersNum;
    std::vector<unique_ptr<Encounter>> m_subMonsters;
    void sumFields();
public:
    Pack(int membersNum ,std::vector<unique_ptr<Encounter>> subMonsters);
    void updateCombatPower() override;

    //string playEvent( Player& player) override;
};

