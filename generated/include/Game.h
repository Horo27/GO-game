//
// Created by Horo on 10/22/2024.
//
#include "Menu.h"

#ifndef GAME_H
#define GAME_H

class Game {
    bool gameState;
public:
    Game(bool gameState = false):gameState(gameState){};
    void changeState(bool state);
    bool currState();
};

#endif //GAME_H
