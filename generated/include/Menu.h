//
// Created by Horo on 10/22/2024.
//
#include "Board.h"
#include "Player.h"
#include "Color.h"
#include <string>
#ifndef MENU_H
#define MENU_H

class Menu {
    int turnNumber;
    friend class Board;
public:
    Menu(int turnNumber = 0):turnNumber(turnNumber){};
    Board declareBoard();
    Player declarePlayer(Color color);
    void playersMove(Player &player1, Player &player2, Board &board);
    void decisionMenu(Player &player1, Player &player2, Board &board);
};

#endif //MENU_H
