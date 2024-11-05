#ifndef DREAMCATCHER_CREATOR_H
#define DREAMCATCHER_CREATOR_H

#include "../Character.h"

class Creator {
public:
    virtual ~Creator() = default;
    virtual std::shared_ptr<Character> createCharacter(nlohmann::json character) = 0;
};


#endif //DREAMCATCHER_CREATOR_H
