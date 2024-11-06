#ifndef DREAMCATCHER_FIGHTSTATE_H
#define DREAMCATCHER_FIGHTSTATE_H

#include "State.h"
#include "../Game.h"

class FightState : public State {
public:
    FightState(StateContext& stateContext, ScenesManager& scenesManager, uint8_t sceneId);

    void upKeyAction() override;
    void downKeyAction() override;
    actionParams& enterKeyAction() override;
    void processEnterAction(actionParams& params) override;

    void setScene(uint8_t sceneID) override { m_sceneId = sceneID; }
    Scene& scene() override { return *m_scenesManager.scene(m_sceneId); }
private:
    std::string makeTitle();
    void processAttack();
    void processResult(AttackResult& result);

    StateContext& m_stateContext;
    ScenesManager& m_scenesManager;
    uint8_t m_sceneId;

    bool m_finished = false;
    bool m_win;
    uint8_t m_enemy;
};


#endif //DREAMCATCHER_FIGHTSTATE_H
