#ifndef DREAMCATCHER_CONSOLE_H
#define DREAMCATCHER_CONSOLE_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <chrono>
#include <thread>

#include "../States/StateContext.h"

class Console {
public:
    Console(StateContext& stateContext);
    void handleInput();
private:
    StateContext& m_stateContext;
    HANDLE m_inputHandle;
    DWORD mode;
};


#endif //DREAMCATCHER_CONSOLE_H
