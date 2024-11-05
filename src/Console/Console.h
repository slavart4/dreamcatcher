#ifndef DREAMCATCHER_CONSOLE_H
#define DREAMCATCHER_CONSOLE_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <chrono>
#include <thread>

#include "../States/StateContext.h"
#include "../Command/Commands/DownKeyCommand.h"
#include "../Command/Commands/UpKeyCommand.h"
#include "../Command/Commands/EnterKeyCommand.h"

class Console {
public:
    Console(StateContext& stateContext);
    void handleInput();
private:
    StateContext&   m_stateContext;
    DownKeyCommand  m_downKeyCommand;
    UpKeyCommand    m_upKeyCommand;
    EnterKeyCommand m_enterKeyCommand;

    HANDLE m_inputHandle;
    DWORD mode;
};


#endif //DREAMCATCHER_CONSOLE_H
