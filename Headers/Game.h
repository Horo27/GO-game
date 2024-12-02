//
// Created by Horo on 10/22/2024.
//
#pragma once
//#include "Menu.h"

#ifndef GAME_H
#define GAME_H

class Game {
     bool gameState;
public:
    Game() = default;
    explicit Game(bool game_state): gameState(game_state) {}
     ~Game() = default;
    //friend std::ostream& operator<<(std::ostream& out, const Game& game);
    bool getState();
    void changeState(bool state);
};

#endif //GAME_H
