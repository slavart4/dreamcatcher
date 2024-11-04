#ifndef DREAMCATCHER_STORYSCENE_H
#define DREAMCATCHER_STORYSCENE_H


#include "../Scene.h"
class StoryScene : public Scene {
public:
    StoryScene(uint8_t id, uint8_t sceneType, std::shared_ptr<Options> options, std::string& title) :
            m_id(id), m_type(sceneType), m_title(title) {};

    std::shared_ptr<Options> options() override { return std::shared_ptr<Options>(); }
    std::shared_ptr<Picture> picture() override { return std::shared_ptr<Picture>(); }

    std::string& title() override { return m_title; }
    std::string& text() override  { return m_texts[0]; }
    uint8_t id() override         { return m_id; }
    uint8_t type() override       { return m_type; }

    void addPicture(std::shared_ptr<Picture> picture) override { m_pictures.push_back(picture); }
    void addText(const std::string& text) override { m_texts.push_back(text); }
private:
    std::vector<std::shared_ptr<Picture>> m_pictures;
    std::vector<std::string> m_texts;
    std::string m_title;
    uint8_t m_id = 0;
    uint8_t m_type = STORY_SCENE;
};

#endif //DREAMCATCHER_STORYSCENE_H
