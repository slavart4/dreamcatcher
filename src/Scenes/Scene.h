#ifndef DREAMCATCHER_SCENE_H
#define DREAMCATCHER_SCENE_H

#include <utility>
#include <vector>
#include <memory>
#include "../Forms/Button/Button.h"
#include "../Forms/Picture/Picture.h"
#include "../Forms/Options/Options.h"

enum SceneType { MENU_SCENE, STORY_SCENE, FIGHT_SCENE };
class Scene {
public:
    virtual std::shared_ptr<Options> options() = 0;
    virtual std::shared_ptr<Picture> picture() = 0;
    virtual std::string& text() = 0;
    virtual std::string& title() = 0;
    virtual uint8_t id() = 0;
    virtual uint8_t type() = 0;

    virtual void addPicture(std::shared_ptr<Picture> picture) = 0;
    virtual void addText(const std::string& text) = 0;
};

#endif //DREAMCATCHER_SCENE_H
