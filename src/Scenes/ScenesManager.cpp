#include "ScenesManager.h"

ScenesManager::ScenesManager() {
    DataIO dataIo("../assets/settings/plot.json");
    nlohmann::json data = dataIo.read()["scenes"];

    for(auto& sceneJson : data) {
        std::string sceneType = sceneJson["type"];
        if(sceneType == "story") {
            director.constructScene(storyBuilder, sceneJson);
            m_scenes[storyBuilder.getResult()->id()] = storyBuilder.getResult();
        }
        else if (sceneType == "menu") {
            director.constructScene(menuBuilder, sceneJson);
            m_scenes[menuBuilder.getResult()->id()] = menuBuilder.getResult();
        }
        else {
            director.constructScene(menuBuilder, sceneJson);
            m_scenes[menuBuilder.getResult()->id()] = menuBuilder.getResult();
        }
    }
}

std::shared_ptr<Scene> ScenesManager::scene(uint8_t id) {
    return m_scenes.at(id);
}
