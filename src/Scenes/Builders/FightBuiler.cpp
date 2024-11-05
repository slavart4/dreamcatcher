#include "FightBuiler.h"

void FightBuiler::setId(nlohmann::json& scene) {
    m_id = scene["id"];
}

void FightBuiler::setType(nlohmann::json& scene) {
    m_type = FIGHT_SCENE;
}

void FightBuiler::setOptions(nlohmann::json& scene) {
    m_options = std::make_shared<Options>();
}

void FightBuiler::setOptionsButtons(nlohmann::json& scene) {
    for(const auto& btnInfo : scene["options"]) {
        actionParams params;
        m_options->addButton(
                Button(
                        params,
                        0,
                        1,
                        btnInfo["name"],
                        btnInfo["chosen"])
        );
    }
}

void FightBuiler::setTitle(nlohmann::json &scene) {
    m_title = scene["title"];
}

void FightBuiler::setCharacters(nlohmann::json &data) {

}

void FightBuiler::createScene() {
    m_scene = std::make_shared<MenuScene>(m_id,m_type, m_options, m_title);
}

void FightBuiler::setTexts(nlohmann::json &scene) {
    for(const auto& text : scene["texts"]) {
        m_scene->addText(text);
    }
}

void FightBuiler::setPictures(nlohmann::json& scene) {
    for(const auto& picturePath : scene["picturePaths"]) {
        m_scene->addPicture(std::make_shared<Picture>(picturePath));
    }
}

std::shared_ptr<Scene> FightBuiler::getResult() {
    return m_scene;
}