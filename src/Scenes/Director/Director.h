#ifndef DREAMCATCHER_DIRECTOR_H
#define DREAMCATCHER_DIRECTOR_H

#include "../Builders/Builder.h"
#include "../../DataIO/DataIO.h"

class Director {
public:
    void constructScene(Builder& builder, nlohmann::json& data);
};


#endif //DREAMCATCHER_DIRECTOR_H
