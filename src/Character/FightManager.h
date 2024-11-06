#ifndef DREAMCATCHER_FIGHTMANAGER_H
#define DREAMCATCHER_FIGHTMANAGER_H

#include "Character.h"

struct AttackResult {
    bool finished = false;
    uint8_t winner = 0;
};

class FightManager {
public:
    AttackResult attack(const std::shared_ptr<Character>& attacker, const std::shared_ptr<Character>& defender);
};


#endif //DREAMCATCHER_FIGHTMANAGER_H
