//
// Created by Horo on 10/22/2024.
//
#include "../include/Board.h"

//Board::Board(int size) : size(size), board(size, std::vector<int>(size, 0)) {}

void Board::displayBoard(){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Board::placeStone(int x, int y, bool color) {
    board[x][y] = color + 1;
}

void Board::clearBoard() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
}