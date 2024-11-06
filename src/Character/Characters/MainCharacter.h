#ifndef DREAMCATCHER_MAINCHARACTER_H
#define DREAMCATCHER_MAINCHARACTER_H

#include "../Character.h"

#include <utility>

class MainCharacter : public Character {
public:
    MainCharacter(uint8_t id, std::string name, std::string picture, uint8_t hp, uint8_t attack, uint8_t agility) :
    m_id(id), m_name(std::move(name)), m_picture(std::move(picture)), m_hp(hp), m_attack(attack), m_agility(agility) {}

    uint8_t id() override { return m_id; }
    uint8_t hp() override { return m_hp; }
    std::string name() override { return m_name; }
    void attack(uint8_t id) override;
    void decreaseHP(uint8_t hp) override;
    bool avoid() override;

    void specialAbility();
private:
    uint8_t m_id;
    std::string m_name;
    std::string m_picture;
    uint8_t m_hp;
    uint8_t m_attack;
    uint8_t m_agility;
};


#endif //DREAMCATCHER_MAINCHARACTER_H
