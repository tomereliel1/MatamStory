#include "Character.h"
Character::Character(const string& type): m_type(type){}

string Character::getType() const {
    return m_type;
}
