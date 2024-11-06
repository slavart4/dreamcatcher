#ifndef DREAMCATCHER_CHARACTER_H
#define DREAMCATCHER_CHARACTER_H

#include <random>
#include <cstdint>
#include <memory>

#include "../DataIO/DataIO.h"

class Character {
public:
    virtual uint8_t id() = 0;
    virtual uint8_t hp() = 0;
    virtual std::string name() = 0;

    virtual void attack(uint8_t id) = 0;
    virtual void specialAbility() = 0;
    virtual void decreaseHP(uint8_t hp) = 0;
    virtual bool avoid() = 0;
};

#endif //DREAMCATCHER_CHARACTER_H
