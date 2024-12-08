//
// Created by Horo on 12/6/2024.
//
#include "Rules.h"
#include "Color.h"

Color Rules::color = WHITE;

bool Rules::basicRule(int lin, int col) {
    if(board.board[lin][col] != EMPTY)
        return false;
    return true;
}
