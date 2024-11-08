#ifndef GAME_H
#define GAME_H

#include <thread>
#include <memory>
#include "Console/Console.h"
#include "Scenes/ScenesManager.h"
#include "States/StateContext.h"
#include "States/StoryState.h"

#include "Character/CharactersManager.h"

class Game {
public:
    void run();
    static Game *GetInstance();
private:
    std::shared_ptr<StateContext> m_stateContext;

// Singleton stuff
public:
    Game(Game &other) = delete;
    void operator=(const Game&) = delete;
private:
    Game() {}
    static Game* singleton_;
};

#endif //GAME_H