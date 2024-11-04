#ifndef DREAMCATCHER_MENUSTATE_H
#define DREAMCATCHER_MENUSTATE_H

#include <memory>
#include "State.h"
class MenuState : public State {
public:
    MenuState(ScenesManager& scenesManager, uint8_t sceneId) : m_scenesManager(scenesManager), m_sceneId(sceneId) {}
    void upKeyAction() override;
    void downKeyAction() override;
    void enterKeyAction() override;
    Scene& scene() override { return *m_scenesManager.scene(m_sceneId); }
private:
    ScenesManager& m_scenesManager;
    uint8_t m_sceneId;
};


#endif //DREAMCATCHER_MENUSTATE_H
