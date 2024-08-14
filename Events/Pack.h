#pragma once

#include "Encounter.h"
#include <string>
#include <memory>
#include <vector>

using std::unique_ptr;
using std::string;
//Represents a pack of monsters
class Pack : public Encounter {
private:
    //number of monsters in the pack
    int m_membersNum;

    //vector which contains the monsters in the pack
    std::vector<unique_ptr<Encounter>> m_subMonsters;

    /**
     * Sum the fields of all sumMonsters and assigning to pack values
     *
     */
    void sumFields();
public:
    /**
     * Constructor - create a pack encounter with submonsters vector
     *
     * @param membersNum - number of the monsters
     * @param subMonsters - vector to copy from
     *
     */
    Pack(int membersNum, std::vector<unique_ptr<Encounter>> subMonsters);

    /**
     * Update the value of combatPower that raised after every fight
     *
     */
    void updateCombatPower() override;

    /**
    * Destructor - default destructor
    */
    ~Pack() override = default;
};

