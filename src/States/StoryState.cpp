#include "StoryState.h"
#include "MenuState.h"
#include "FightState.h"

actionParams &StoryState::enterKeyAction() {
    actionParams params = m_scenesManager.scene(m_sceneId)->options()->action();
    if(params.toScene >= 0) {
        if(m_scenesManager.scene(params.toScene)->type() == MENU_SCENE) {
            m_stateContext.setState(std::make_shared<MenuState>(m_stateContext, m_scenesManager, params.toScene));
        }
        if(m_scenesManager.scene(params.toScene)->type() == FIGHT_SCENE) {
            m_stateContext.setState(std::make_shared<FightState>(m_stateContext, m_scenesManager, params.toScene));
        }
    }
    return m_scenesManager.scene(m_sceneId)->options()->action();
}
