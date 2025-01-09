//
// Created by Horo on 12/6/2024.
//
#include "../Headers/Rules.h"
#include "../Headers/Color.h"

Color Rules::color = WHITE;

bool Rules::basicRule(int lin, int col) {
    auto *derviedPtr = dynamic_cast<BoardProduct*>(board);
    if(derviedPtr->board[lin][col] != EMPTY)
        return false;
    return true;
}
