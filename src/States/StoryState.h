#ifndef DREAMCATCHER_STORYSTATE_H
#define DREAMCATCHER_STORYSTATE_H

#include <memory>
#include "StateContext.h"

class StoryState : public State {
public:
    StoryState(StateContext& stateContext,ScenesManager& scenesManager, uint8_t sceneId) :
    m_stateContext(stateContext), m_scenesManager(scenesManager), m_sceneId(sceneId) {}

    void upKeyAction() override {};
    void downKeyAction() override {};
    actionParams& enterKeyAction() override;
    void processEnterAction(actionParams &params) override;

    void setScene(uint8_t sceneID) override { m_sceneId = sceneID; }
    Scene& scene() override { return *m_scenesManager.scene(m_sceneId); }
private:
    StateContext &m_stateContext;
    ScenesManager& m_scenesManager;
    uint8_t m_sceneId;
};


#endif //DREAMCATCHER_STORYSTATE_H
