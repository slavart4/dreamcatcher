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
    Scene(uint8_t id, uint8_t sceneType, std::shared_ptr<Options> options, std::string  text) :
            m_id(id), m_type(sceneType), m_options(std::move(options)), m_text(std::move(text)) {};

    std::string& text() { return m_text; }
    std::shared_ptr<Options> options()  { return m_options; }
    std::shared_ptr<Picture> picture()  { return m_pictures[m_options->button(m_options->chosen()).picture()]; }
    uint8_t id()        { return m_id; }
    uint8_t type()      { return m_type; }

    void setPicture(std::shared_ptr<Picture> picture) { m_pictures.push_back(picture); }
private:
    uint8_t m_id = 0;
    uint8_t m_type = MENU_SCENE;
    std::vector<std::shared_ptr<Picture>> m_pictures;
    std::shared_ptr<Options> m_options;
    std::string m_text;
};

#endif //DREAMCATCHER_SCENE_H
