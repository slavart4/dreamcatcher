#include "StoryBuilder.h"

void StoryBuilder::setId(nlohmann::json& scene) {
    m_id = scene["id"];
}

void StoryBuilder::setType(nlohmann::json& scene) {
    m_type = STORY_SCENE;
}

void StoryBuilder::setTitle(nlohmann::json &scene) {
    m_title = scene["title"];
}

void StoryBuilder::setTexts(nlohmann::json &scene) {
    for(const auto& text : scene["texts"]) {
        m_scene->addText(text);
    }
}

void StoryBuilder::createScene() {
    m_scene = std::make_shared<StoryScene>(m_id,m_type, m_options, m_title);
}

void StoryBuilder::setPictures(nlohmann::json& scene) {
    for(const auto& picturePath : scene["picturePaths"]) {
        m_scene->addPicture(std::make_shared<Picture>(picturePath));
    }
}

std::shared_ptr<Scene> StoryBuilder::getResult() {
    return m_scene;
}