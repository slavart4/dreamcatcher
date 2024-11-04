#include "StoryBuilder.h"

void StoryBuilder::setId(nlohmann::json& scene) {
    m_id = scene["id"];
}

void StoryBuilder::setType(nlohmann::json& scene) {
    m_type = STORY_SCENE;
}

void StoryBuilder::setText(nlohmann::json& scene) {
    m_text = scene["text"];
}

void StoryBuilder::createScene() {
    m_scene = std::make_shared<Scene>(m_id,m_type, m_options, m_text);
}

void StoryBuilder::setPictures(nlohmann::json& scene) {
    for(const auto& picturePath : scene["picturePaths"]) {
        m_scene->setPicture(std::make_shared<Picture>(picturePath));
    }
}

std::shared_ptr<Scene> StoryBuilder::getResult() {
    return m_scene;
}