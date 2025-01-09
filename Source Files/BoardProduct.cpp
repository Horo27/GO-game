//
// Created by Horo on 1/8/2025.
//

#include "../Headers/Factory.h"
#ifndef BOARDPRODUCT_H
#define BOARDPRODUCT_H

std::ostream& operator<<(std::ostream& out, const BoardProduct& b) {
    out<<"Size: "<<b.size<<"\n";
    out<<"Board:\n";

    for(int i=0; i<b.size; i++) {
        for(int j=0; j<b.size; j++) {
            out << b.board[i][j] << " ";
        }
        out<<"\n";
    }

    return out;
}

void BoardProduct::placeStone(int x, int y, Color color) {
    board[x][y] = color;
}


void BoardProduct::clearBoard() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = EMPTY;
        }
    }
}

BoardProduct &BoardProduct::operator=(const BoardProduct &other) {
    if(this == &other)
        return *this;
    size = other.size;
    board = other.board;
    return *this;
}


#endif //BOARDPRODUCT_H
