//
// Created by Horo on 10/22/2024.
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

class Board {
    int size;
    std::vector<std::vector<int>> board;

public:
    Board (int size = 19): size(size),board(size, std::vector<int>(size, 0)) {}
    void placeStone(int x, int y, bool color);
    void clearBoard(); //CLEARS THE BOARD
   /*
    bool checkMove(int x, int y, int player);*/
    void displayBoard();
};

#endif //BOARD_H
