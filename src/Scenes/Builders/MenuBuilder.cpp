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
        m_options->addButton(
                Button(btnInfo["toScene"],btnInfo["pictureIndex"],btnInfo["name"],btnInfo["chosen"])
                );
    }
}

void MenuBuilder::setText(nlohmann::json& scene) {
    m_text = scene["text"];
}

void MenuBuilder::createScene() {
    m_scene = std::make_shared<Scene>(m_id,m_type, m_options, m_text);
}

void MenuBuilder::setPictures(nlohmann::json& scene) {
    for(const auto& picturePath : scene["picturePaths"]) {
        m_scene->setPicture(std::make_shared<Picture>(picturePath));
    }
}

std::shared_ptr<Scene> MenuBuilder::getResult() {
    return m_scene;
}