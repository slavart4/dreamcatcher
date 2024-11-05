#include "ScenesManager.h"
#include "../Renderer/Renderer.h"

ScenesManager::ScenesManager() {
    DataIO dataIo("../assets/settings/plot.json");
    nlohmann::json data = dataIo.read()["scenes"];

    for(auto& sceneJson : data) {
        std::string sceneType = sceneJson["type"];
        if(sceneType == "story") {
            m_director.constructScene(m_storyBuilder, sceneJson);
            m_scenes[m_storyBuilder.getResult()->id()] = m_storyBuilder.getResult();
        }
        else if (sceneType == "menu") {
            m_director.constructScene(m_menuBuilder, sceneJson);
            m_scenes[m_menuBuilder.getResult()->id()] = m_menuBuilder.getResult();
        }
        else if (sceneType == "fight") {
            m_director.constructScene(m_fightBuiler, sceneJson);
            m_scenes[m_fightBuiler.getResult()->id()] = m_fightBuiler.getResult();
        }
        else {
            m_director.constructScene(m_menuBuilder, sceneJson);
            m_scenes[m_menuBuilder.getResult()->id()] = m_menuBuilder.getResult();
        }
    }
    Renderer::GetInstance()->draw(*m_scenes.at(0));
}

std::shared_ptr<Scene> ScenesManager::scene(uint8_t id) {
    return m_scenes.at(id);
}
