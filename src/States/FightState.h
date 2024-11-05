#ifndef DREAMCATCHER_FIGHTSTATE_H
#define DREAMCATCHER_FIGHTSTATE_H

#include "State.h"
#include "../Game.h"

class FightState : public State {
public:
    FightState(ScenesManager& scenesManager, uint8_t sceneId) : m_scenesManager(scenesManager), m_sceneId(sceneId) {}
    void upKeyAction() override {}
    void downKeyAction() override {}
    actionParams& enterKeyAction() override {}
    void setScene(uint8_t sceneID) override { m_sceneId = sceneID; }
private:
    ScenesManager& m_scenesManager;
    uint8_t m_sceneId;
};


#endif //DREAMCATCHER_FIGHTSTATE_H
