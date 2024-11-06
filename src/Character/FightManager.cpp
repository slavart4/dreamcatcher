#include "FightManager.h"

AttackResult FightManager::attack(const std::shared_ptr<Character>& attacker, const std::shared_ptr<Character>& defender) {
    AttackResult result;

    attacker->attack(defender->id());
    defender->attack(attacker->id());
    if(defender->hp() == 0) {
        result.winner = attacker->id();
        result.finished = true;
    }
    if(attacker->hp() == 0) {
        result.winner = defender->id();
        result.finished = true;
    }

    return result;
}
