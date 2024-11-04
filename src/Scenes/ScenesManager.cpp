#include "ScenesManager.h"

ScenesManager::ScenesManager() {
    DataIO dataIo("../assets/settings/plot.json");
    nlohmann::json data = dataIo.read()["scenes"];

    for(auto& sceneJson : data) {
        director.constructMenuScene(builder, sceneJson);
        m_scenes[builder.getResult()->id()] = builder.getResult();
    }
}

std::shared_ptr<Scene> ScenesManager::scene(uint8_t id) {
    return m_scenes.at(id);
}
