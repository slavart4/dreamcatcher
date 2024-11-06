#ifndef DREAMCATCHER_MENUSCENE_H
#define DREAMCATCHER_MENUSCENE_H

#include "../Scene.h"
class MenuScene : public Scene {
public:
    MenuScene(uint8_t id, uint8_t sceneType, std::shared_ptr<Options> options, std::string& title) :
    m_id(id), m_type(sceneType), m_options(std::move(options)), m_title(title) {};

    std::shared_ptr<Options> options() override { return m_options; }
    std::shared_ptr<Picture> picture() override { return m_pictures[m_options->button(m_options->chosen()).pictureIndex()]; }
    std::string& text() override  { return m_texts[m_options->button(m_options->chosen()).textIndex()]; }
    std::string& title() override { return m_title; }
    uint8_t id() override         { return m_id; }
    uint8_t type() override       { return m_type; }
    uint8_t enemy() override {}

    void addPicture(std::shared_ptr<Picture> picture) override { m_pictures.push_back(picture); }
    void addText(const std::string& text) override { m_texts.push_back(text); }
    void setTitle(const std::string& title) override { m_title = title; }
private:
    uint8_t m_id = 0;
    uint8_t m_type = MENU_SCENE;
    std::vector<std::shared_ptr<Picture>> m_pictures;
    std::vector<std::string> m_texts;
    std::shared_ptr<Options> m_options;
    std::string m_title;
};


#endif //DREAMCATCHER_MENUSCENE_H
