#ifndef DREAMCATCHER_STORYBUILDER_H
#define DREAMCATCHER_STORYBUILDER_H

#include "Builder.h"

class StoryBuilder : public Builder {
public:
    void setId(nlohmann::json& scene) override;
    void setType(nlohmann::json& scene) override;
    void setOptions(nlohmann::json& scene) override {};
    void setOptionsButtons(nlohmann::json& scene) override {};
    void setTitle(nlohmann::json& scene) override;
    void setTexts(nlohmann::json& scene) override;
    void createScene() override;
    void setPictures(nlohmann::json& scene) override;

    std::shared_ptr<Scene> getResult();
private:
    std::shared_ptr<Scene> m_scene;
    std::shared_ptr<Picture> m_picture;
    std::shared_ptr<Options> m_options;
    std::string m_title;
    uint8_t m_id = 0;
    uint8_t m_type = MENU_SCENE;
};


#endif //DREAMCATCHER_STORYBUILDER_H
