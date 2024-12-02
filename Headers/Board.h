//
// Created by Horo on 10/22/2024.
//

#ifndef BOARD_H
#define BOARD_H

#include "Color.h"
#include "Game.h"
#include <iostream>
#include <vector>

class Board {
    int size;
    std::vector<std::vector<int>> board;
public:
    explicit Board (int size = 19): size(size),board(size, std::vector<int>(size, EMPTY)) {}
    friend std::ostream& operator<<(std::ostream& os, const Board& b);
    ~Board()=default;
    void placeStone(int x, int y, Color color);
    void clearBoard(); //CLEARS THE BOARD
    bool isCaptured(int x, int y, Color color);
    void removeStones(int x,int y, Color color);

    Board (Board& other): size(other.size), board(other.board) {}
    Board& operator=(const Board& other);
};

#endif //BOARD_H
