#ifndef DREAMCATCHER_SCENESMANAGER_H
#define DREAMCATCHER_SCENESMANAGER_H

#include <unordered_map>
#include <memory>
#include <chrono>
#include <thread>

#include "Scene.h"
#include "Builders/MenuBuilder.h"
#include "Director/Director.h"

class ScenesManager {
public:
    ScenesManager();
    std::shared_ptr<Scene> scene(uint8_t id);
private:
    std::unordered_map<uint8_t, std::shared_ptr<Scene>> m_scenes;
    Director director;
    MenuBuilder builder;
};


#endif //DREAMCATCHER_SCENESMANAGER_H
