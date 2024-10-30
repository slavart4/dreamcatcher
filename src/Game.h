#ifndef GAME_H
#define GAME_H
#include <iostream>


using namespace std;

class Game {
public:
    void run();
    static Game *GetInstance();
public:
    Game(Game &other) = delete;
    void operator=(const Game&) = delete;
private:
    explicit Game() {}
    static Game* singleton_;
};

#endif //GAME_H