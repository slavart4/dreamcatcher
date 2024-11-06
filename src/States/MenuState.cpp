#include "MenuState.h"
#include "StoryState.h"
#include "FightState.h"

void MenuState::upKeyAction() {
    m_scenesManager.scene(m_sceneId)->options()->decreaseChosen();
}

void MenuState::downKeyAction() {
    m_scenesManager.scene(m_sceneId)->options()->increaseChosen();
}

actionParams& MenuState::enterKeyAction() {
    actionParams params = m_scenesManager.scene(m_sceneId)->options()->action();
    processEnterAction(params);
    return m_scenesManager.scene(m_sceneId)->options()->action();
}

void MenuState::processEnterAction(actionParams &params) {
    if(params.setMainChar >= 0) {
        CharactersManager::GetInstance()->setMainCharacter(params.setMainChar);
    }
    if(params.toScene >= 0) {
        if(m_scenesManager.scene(params.toScene)->type() == STORY_SCENE) {
            m_stateContext.setState(std::make_shared<StoryState>(m_stateContext, m_scenesManager, params.toScene));
        }
        if(m_scenesManager.scene(params.toScene)->type() == FIGHT_SCENE) {
            m_stateContext.setState(std::make_shared<FightState>(m_stateContext, m_scenesManager, params.toScene));
        }
    }
}
