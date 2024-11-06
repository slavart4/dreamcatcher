#ifndef DREAMCATCHER_MENUSTATE_H
#define DREAMCATCHER_MENUSTATE_H

#include <memory>
#include "StateContext.h"

class MenuState : public State {
public:
    MenuState(StateContext& stateContext, ScenesManager& scenesManager, uint8_t sceneId) :
    m_stateContext(stateContext), m_scenesManager(scenesManager), m_sceneId(sceneId) {}

    void upKeyAction() override;
    void downKeyAction() override;
    actionParams& enterKeyAction() override;
    void setScene(uint8_t sceneID) override { m_sceneId = sceneID; }
    Scene& scene() override { return *m_scenesManager.scene(m_sceneId); }
private:
    StateContext& m_stateContext;
    ScenesManager& m_scenesManager;
    uint8_t m_sceneId;
};


#endif //DREAMCATCHER_MENUSTATE_H
