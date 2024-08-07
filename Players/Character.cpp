#include "Character.h"
Character::Character(string &type): m_type(type){}

string Character::getType() const {
    return m_type;
}
