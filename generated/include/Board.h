//
// Created by Horo on 10/22/2024.
//

#ifndef BOARD_H
#define BOARD_H

#include "Color.h"
#include <iostream>
#include <vector>

class Board {
    int size;
    std::vector<std::vector<int>> board;

public:
    Board (int size = 19): size(size),board(size, std::vector<int>(size, EMPTY)) {}
    void placeStone(int x, int y, Color color);
    void clearBoard(); //CLEARS THE BOARD
    void displayBoard();
    bool isCaptured(int x, int y, Color color);
    void removeStones(int x,int y, Color color);
};

#endif //BOARD_H
