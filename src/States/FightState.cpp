#include "FightState.h"

FightState::FightState(StateContext &stateContext, ScenesManager &scenesManager, uint8_t sceneId) :
        m_stateContext(stateContext), m_scenesManager(scenesManager), m_sceneId(sceneId)
{
    m_scenesManager.scene(m_sceneId)->setTitle(makeTitle());
    m_enemy = m_scenesManager.scene(m_sceneId)->enemy();
}


void FightState::upKeyAction() {
    m_scenesManager.scene(m_sceneId)->options()->decreaseChosen();
}

void FightState::downKeyAction() {
    m_scenesManager.scene(m_sceneId)->options()->increaseChosen();
}

actionParams& FightState::enterKeyAction() {
    actionParams& params = m_scenesManager.scene(m_sceneId)->options()->action();
    processEnterAction(params);
    return m_scenesManager.scene(m_sceneId)->options()->action();
}

void FightState::processEnterAction(actionParams &params) {
    if(!m_finished && params.attack >= 0) {
        processAttack();
    }
    if(!m_finished && params.specAbility >= 0) {
        CharactersManager::GetInstance()->mainCharacter()->specialAbility();
        m_scenesManager.scene(m_sceneId)->setTitle(makeTitle());
    }
    if(m_finished && m_win && params.onWinScene >= 0) {
        if(m_scenesManager.scene(params.onWinScene)->type() == STORY_SCENE) {
            m_stateContext.setState(std::make_shared<StoryState>(m_stateContext, m_scenesManager, params.onWinScene));
        }
    }
    if(m_finished && !m_win && params.onLoseScene >= 0) {
        if(m_scenesManager.scene(params.onLoseScene)->type() == STORY_SCENE) {
            m_stateContext.setState(std::make_shared<StoryState>(m_stateContext, m_scenesManager, params.onLoseScene));
        }
    }
}

void FightState::processAttack() {
    AttackResult res = CharactersManager::GetInstance()->attack(m_enemy);
    if(res.finished) {
        processResult(res);
    } else {
        m_scenesManager.scene(m_sceneId)->setTitle(makeTitle());
    }
}

void FightState::processResult(AttackResult& result) {
    m_finished = true;
    m_win = (result.winner != m_enemy);

    m_scenesManager.scene(m_sceneId)->setTitle(m_win ? "You won!" : "You lose...");
    m_scenesManager.scene(m_sceneId)->options()->reverseVisible();
}

std::string FightState::makeTitle() {
    std::shared_ptr<Character> main = CharactersManager::GetInstance()->mainCharacter();
    std::shared_ptr<Character> enemy = CharactersManager::GetInstance()->character(m_scenesManager.scene(m_sceneId)->enemy());

    std::string title = main->name() + "(" + std::to_string(main->hp()) + " hp)" +
                        " vs "
                        + enemy->name() + "(" + std::to_string(enemy->hp()) + " hp)";
    return title;
}