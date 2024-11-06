#include "MainCharacter.h"
#include "../CharactersManager.h"

void MainCharacter::attack(uint8_t id) {
    CharactersManager::GetInstance()->character(id)->decreaseHP(m_attack);
}

void MainCharacter::decreaseHP(uint8_t hp) {
    if(avoid()) return;
    if(m_hp <= hp) {
        m_hp = 0;
    } else {
        m_hp -= hp;
    }
}

bool MainCharacter::avoid() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 100);

    return (static_cast<uint8_t>(distrib(gen)) <= m_agility);
}

void MainCharacter::specialAbility() {
    m_attack += 5;
}
