#ifndef DREAMCATCHER_FIGHTSTATE_H
#define DREAMCATCHER_FIGHTSTATE_H

#include "State.h"
#include "../Game.h"

class FightState : public State {
public:
    FightState(Scene& scene) : m_scene(scene) {}
    void upKeyAction() override {}
    void downKeyAction() override {}
    void enterKeyAction() override {}
private:
    Scene& m_scene;
};


#endif //DREAMCATCHER_FIGHTSTATE_H
