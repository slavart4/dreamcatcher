#ifndef DREAMCATCHER_ENEMYCHARACTER_H
#define DREAMCATCHER_ENEMYCHARACTER_H

#include "../Character.h"

class EnemyCharacter : public Character {
public:
    EnemyCharacter(uint8_t id, std::string name, std::string picture, uint8_t hp, uint8_t attack, uint8_t agility) :
    m_id(id), m_name(std::move(name)), m_picture(std::move(picture)), m_hp(hp), m_attack(attack), m_agility(agility) {}

    uint8_t id() override { return m_id; }
    void attack(Character& character) override;
    void decreaseHP(uint8_t hp) override;
    bool avoid() override;
private:
    uint8_t m_id;
    std::string m_name;
    std::string m_picture;
    uint8_t m_hp;
    uint8_t m_attack;
    uint8_t m_agility;
};


#endif //DREAMCATCHER_ENEMYCHARACTER_H
