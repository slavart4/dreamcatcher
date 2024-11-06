#include "StoryBuilder.h"

void StoryBuilder::setId(nlohmann::json& scene) {
    m_id = scene["id"];
}

void StoryBuilder::setType(nlohmann::json& scene) {
    m_type = STORY_SCENE;
}

void StoryBuilder::setOptions(nlohmann::json& scene) {
    m_options = std::make_shared<Options>();
}

void StoryBuilder::setOptionsButtons(nlohmann::json& scene) {
    actionParams params;
    if(scene["options"][0]["commands"][0]["name"] == "toScene") {
        params.toScene = scene["options"][0]["commands"][0]["value"];
    }

    m_options->addButton(
            Button(
                    params,
                    0,
                    0,
                    scene["options"][0]["name"],
                    true,
                    true)
    );
}

void StoryBuilder::setTitle(nlohmann::json &scene) {
    m_title = scene["title"];
}

void StoryBuilder::createScene() {
    m_scene = std::make_shared<StoryScene>(m_id,m_type, m_options, m_title);
}

void StoryBuilder::setTexts(nlohmann::json &scene) {
    m_scene->addText(scene["texts"][0]);
}

void StoryBuilder::setPictures(nlohmann::json& scene) {
    m_scene->addPicture(std::make_shared<Picture>(scene["picturePaths"][0]));
}

std::shared_ptr<Scene> StoryBuilder::getResult() {
    return m_scene;
}