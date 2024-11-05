#ifndef DREAMCATCHER_STORYSCENE_H
#define DREAMCATCHER_STORYSCENE_H


#include "../Scene.h"
class StoryScene : public Scene {
public:
    StoryScene(uint8_t id, uint8_t sceneType, std::shared_ptr<Options> options, std::string& title) :
            m_id(id), m_type(sceneType), m_options(std::move(options)), m_title(title) {};

    std::shared_ptr<Options> options() override { return m_options; }
    std::shared_ptr<Picture> picture() override { return m_picture; }

    std::string& title() override { return m_title; }
    std::string& text() override  { return m_text; }
    uint8_t id() override         { return m_id; }
    uint8_t type() override       { return m_type; }

    void addPicture(std::shared_ptr<Picture> picture) override { m_picture = picture; }
    void addText(const std::string& text) override { m_text = text; }
private:
    uint8_t m_id = 0;
    uint8_t m_type = STORY_SCENE;
    std::shared_ptr<Picture> m_picture;
    std::string m_text;
    std::shared_ptr<Options> m_options;
    std::string m_title;
};

#endif //DREAMCATCHER_STORYSCENE_H
