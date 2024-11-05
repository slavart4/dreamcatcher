#include "EnemyCharacter.h"

void EnemyCharacter::attack(Character &character) {
    character.decreaseHP(m_attack);
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