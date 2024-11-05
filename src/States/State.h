#ifndef DREAMCATCHER_STATE_H
#define DREAMCATCHER_STATE_H

#include "../Scenes/ScenesManager.h"

class State {
public:
    virtual ~State() = default;
    virtual void upKeyAction() = 0;
    virtual void downKeyAction() = 0;
    virtual actionParams& enterKeyAction() = 0;
    virtual void setScene(uint8_t sceneID) = 0;
    virtual Scene& scene() = 0;
};


#endif //DREAMCATCHER_STATE_H
