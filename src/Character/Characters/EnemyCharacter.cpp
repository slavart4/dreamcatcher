#include "EnemyCharacter.h"
#include "../CharactersManager.h"

void EnemyCharacter::attack(uint8_t id) {
    CharactersManager::GetInstance()->character(id)->decreaseHP(m_attack);
}

void EnemyCharacter::decreaseHP(uint8_t hp) {
    if(avoid()) return;
    if(m_hp <= hp) {
        m_hp = 0;
    } else {
        m_hp -= hp;
    }
}

bool EnemyCharacter::avoid() {
    return false;
}