#pragma once

#include <string>
#include <memory>
#include <map>
#include "Factory.h"
#include "Character.h"

using std::shared_ptr;
using std::string;
using std::make_shared;

/**
 * CharacterFactory - a class for creating Character objects
 */
class CharacterFactory : public Factory<Character> {
private:
    // m_characters - a map that stores shared pointers to Character objects by their type
    std::map<string, shared_ptr<Character>> m_characters;

public:
    /**
     * Constructor - initializes the CharacterFactory and its character map
     */
    CharacterFactory();

    /**
     * create - creates a Character object based on the specified type
     *
     * @param type - the type of Character to create
     * @return - a shared pointer to the created Character object
     */
    shared_ptr<Character> create(const string& type) override;

    /**
     * Destructor - default destructor for the CharacterFactory class
     */
    ~CharacterFactory() override = default;
};
