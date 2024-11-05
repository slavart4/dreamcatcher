#ifndef DREAMCATCHER_UPKEYCOMMAND_H
#define DREAMCATCHER_UPKEYCOMMAND_H

#include "../Command.h"

class UpKeyCommand : public Command {
public:
    void execute(StateContext& stateContext) override;
};


#endif //DREAMCATCHER_UPKEYCOMMAND_H
