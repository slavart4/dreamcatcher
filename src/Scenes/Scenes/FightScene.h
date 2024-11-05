#ifndef DREAMCATCHER_FIGHTSCENE_H
#define DREAMCATCHER_FIGHTSCENE_H

#include "../Scene.h"
#include "../../Character/Character.h"

class FightScene : public Scene {
public:
    FightScene(uint8_t id,
               uint8_t sceneType,
               std::shared_ptr<Options> options,
               std::string& title,
               Character& character,
               Character& enemy) :
    m_id(id),
    m_type(sceneType),
    m_options(std::move(options)),
    m_title(title),
    m_character(character),
    m_enemy(enemy) {};

    std::shared_ptr<Options> options() override { return m_options; }
    std::shared_ptr<Picture> picture() override { return m_pictures[m_options->button(m_options->chosen()).pictureIndex()]; }
    std::string& text() override  { return m_texts[m_options->button(m_options->chosen()).textIndex()]; }
    std::string& title() override { return m_title; }
    uint8_t id() override         { return m_id; }
    uint8_t type() override       { return m_type; }

    void addPicture(std::shared_ptr<Picture> picture) override { m_pictures.push_back(picture); }
    void addText(const std::string& text) override { m_texts.push_back(text); }

    Character& character() { return m_character; }
    Character& enemy() { return m_enemy; }
private:
    uint8_t m_id = 0;
    uint8_t m_type = FIGHT_SCENE;
    std::vector<std::shared_ptr<Picture>> m_pictures;
    std::vector<std::string> m_texts;
    std::shared_ptr<Options> m_options;
    std::string m_title;

    Character& m_character;
    Character& m_enemy;
};


#endif //DREAMCATCHER_FIGHTSCENE_H
