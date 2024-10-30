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
    std::cout << "Enter your name\n";
    std::string name;
    std::getline( std::cin, name );

    std::cout << "Hello " + name << std::endl;
}