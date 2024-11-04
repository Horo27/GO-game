//
// Created by Horo on 10/22/2024.
//
#pragma once
#include "Board.h"
#include "Player.h"
#include "Color.h"
#include <fstream>
#include <iostream>
#include <string>
#ifndef MENU_H
#define MENU_H

class Menu {
    std::istream& inputMethod;
    int turnNumber;
public:
    explicit Menu(std::istream& inputMethod = std::cin,int turnNumber = 0):inputMethod(inputMethod), turnNumber(turnNumber){};
    friend std::ostream& operator<<(std::ostream& out, const Menu& m);
    ~Menu()=default;
    Board declareBoard();
    Player declarePlayer(Color color);
    void playersMove(Player &player1, Player &player2, Board &board);
    void decisionMenu(Player &player1, Player &player2, Board &board);
    bool checkInputMethod() const;
};

#endif //MENU_H
