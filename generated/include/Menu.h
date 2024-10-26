//
// Created by Horo on 10/22/2024.
//
#include "Board.h"
#include "Player.h"
#include <string>
#ifndef MENU_H
#define MENU_H

class Menu {
    bool gameStatus;

public:
    Menu(bool gameStatus = false) : gameStatus(gameStatus) {}
    Board declareBoard();
    Player declarePlayer(std::string color);
};

#endif //MENU_H
