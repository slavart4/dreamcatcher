#include "Console.h"

Console::Console(StateContext& stateContext) : m_stateContext(stateContext) {
    m_inputHandle = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(m_inputHandle, &mode);
    SetConsoleMode(m_inputHandle, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT));
}

void Console::handleInput() {
    INPUT_RECORD inputRecord;
    DWORD events;
    while (true) {
        ReadConsoleInput(m_inputHandle, &inputRecord, 1, &events);
        if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown) {
            switch (inputRecord.Event.KeyEvent.wVirtualKeyCode) {
                case VK_UP:
                    m_upKeyCommand.execute(m_stateContext);
                    break;
                case VK_DOWN:
                    m_downKeyCommand.execute(m_stateContext);
                    break;
                case VK_RETURN:
                    m_enterKeyCommand.execute(m_stateContext);
                    break;
                case 'Q':
                case 'q':
                    std::cout << "Exit..." << std::endl;
                    return;
                default:
                    break;
            }
        }
    }
}

