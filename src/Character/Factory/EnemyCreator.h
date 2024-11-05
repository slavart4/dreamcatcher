#ifndef DREAMCATCHER_ENEMYCREATOR_H
#define DREAMCATCHER_ENEMYCREATOR_H

#include "Creator.h"

class EnemyCreator : public Creator {
public:
    std::shared_ptr<Character> createCharacter(nlohmann::json character) override;
};


#endif //DREAMCATCHER_ENEMYCREATOR_H
