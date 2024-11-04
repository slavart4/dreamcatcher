#ifndef DREAMCATCHER_BUILDER_H
#define DREAMCATCHER_BUILDER_H

#include <nlohmann/json.hpp>
#include "../Scene.h"
#include "../../Forms/Options/Options.h"
#include "../../Forms/Picture/Picture.h"
#include "../../Forms/Button/Button.h"

class Builder {
public:
    virtual void setId(nlohmann::json& data) = 0;
    virtual void setType(nlohmann::json& data) = 0;
    virtual void setOptions(nlohmann::json& data) = 0;
    virtual void setOptionsButtons(nlohmann::json& data) = 0;
    virtual void setText(nlohmann::json& data) = 0;
    virtual void createScene() = 0;
    virtual void setPictures(nlohmann::json& data) = 0;
};


#endif //DREAMCATCHER_BUILDER_H