#ifndef DREAMCATCHER_MAINCHARACTER_H
#define DREAMCATCHER_MAINCHARACTER_H

#include "Character.h"

#include <utility>

class MainCharacter : public Character {
public:
    MainCharacter(std::string name, uint8_t hp, uint8_t attack, uint8_t agility) :
    m_name(std::move(name)), m_hp(hp), m_attack(attack), m_agility(agility) {}
    void attack(Character& character) override;
    void decreaseHP(uint8_t hp) override;
    bool avoid() override;

    void specialAbility();
private:
    std::string m_name;
    uint8_t m_hp;
    uint8_t m_attack;
    uint8_t m_agility;
};


#endif //DREAMCATCHER_MAINCHARACTER_H
