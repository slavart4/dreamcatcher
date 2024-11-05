#ifndef DREAMCATCHER_CHARACTERCREATOR_H
#define DREAMCATCHER_CHARACTERCREATOR_H

#include "Creator.h"

class CharacterCreator : public Creator {
public:
    std::shared_ptr<Character> createCharacter(nlohmann::json character) override;
};


#endif //DREAMCATCHER_CHARACTERCREATOR_H
