#ifndef DREAMCATCHER_STATECONTEXT_H
#define DREAMCATCHER_STATECONTEXT_H

#include <memory>
#include "State.h"
#include "../Renderer/Renderer.h"
class StateContext {
public:
    StateContext(std::unique_ptr<State>&& state) : m_state(std::move(state)) {
        renderer.draw(m_state->scene());
    }
    void setState(std::unique_ptr<State>&& state) {
        m_state = std::move(state);
    }
//    std::unique_ptr<State> state() {
//        return std::move(m_state);
//    }

    void upKeyAction() {
        m_state->upKeyAction();
        renderer.draw(m_state->scene());
    }
    void downKeyAction() {
        m_state->downKeyAction();
        renderer.draw(m_state->scene());
    }
    void enterKeyAction() {
        m_state->enterKeyAction();
        renderer.draw(m_state->scene());
    }
private:
    std::unique_ptr<State> m_state;
    Renderer renderer;
};


#endif //DREAMCATCHER_STATECONTEXT_H
