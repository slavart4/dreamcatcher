#ifndef DREAMCATCHER_DIRECTOR_H
#define DREAMCATCHER_DIRECTOR_H

#include "../Builders/Builder.h"
#include "../../DataIO/DataIO.h"

class Director {
public:
    void constructMenuScene(Builder& builder, nlohmann::json& data);
};


#endif //DREAMCATCHER_DIRECTOR_H
