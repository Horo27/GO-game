//
// Created by Horo on 10/22/2024.
//
#include "Board.h"
#include "Color.h"
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    std::string name;
    Color color; //0 for white 1 for black
    int caputres;
    int teritoryPoints;
    friend class Board;

public:
    Player(std::string name = "NULL", Color color = WHITE, int caputres = 0, int teritoryPoints = 0):
    name(name), color(color), caputres(caputres), teritoryPoints(teritoryPoints){};
    void displayStats();
    //void placeStone(Board &board, int x, int y);
    std::string getName();
    //pass();
};

#endif //PLAYER_H
