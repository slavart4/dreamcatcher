#include "MenuBuilder.h"

void MenuBuilder::setId(nlohmann::json& scene) {
    m_id = scene["id"];
}

void MenuBuilder::setType(nlohmann::json& scene) {
    m_type = MENU_SCENE;
}

void MenuBuilder::setOptions(nlohmann::json& scene) {
    m_options = std::make_shared<Options>();
}

void MenuBuilder::setOptionsButtons(nlohmann::json& scene) {
    for(const auto& btnInfo : scene["options"]) {
        actionParams params;
        if(btnInfo["command"]["name"] == "toScene") {
            params.toScene = btnInfo["command"]["value"];
        }

        m_options->addButton(
        Button(
                params,
                btnInfo["textIndex"],
                btnInfo["pictureIndex"],
                btnInfo["name"],
                btnInfo["chosen"])
                );
    }
}

void MenuBuilder::setTitle(nlohmann::json &scene) {
    m_title = scene["title"];
}

void MenuBuilder::createScene() {
    m_scene = std::make_shared<MenuScene>(m_id,m_type, m_options, m_title);
}

void MenuBuilder::setTexts(nlohmann::json &scene) {
    for(const auto& text : scene["texts"]) {
        m_scene->addText(text);
    }
}

void MenuBuilder::setPictures(nlohmann::json& scene) {
    for(const auto& picturePath : scene["picturePaths"]) {
        m_scene->addPicture(std::make_shared<Picture>(picturePath));
    }
}

std::shared_ptr<Scene> MenuBuilder::getResult() {
    return m_scene;
}