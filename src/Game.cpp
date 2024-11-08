#include "Game.h"

Game* Game::singleton_= nullptr;

Game *Game::GetInstance()
{
    if(singleton_==nullptr){
        singleton_ = new Game();
    }
    return singleton_;
}

void Game::run() {
    ScenesManager manager;
    StateContext context;
    context.setState(std::make_unique<StoryState>(context, manager, 0));

    Console console(context);
    console.handleInput();
}