//
// Created by Horo on 10/22/2024.
//
#pragma once

#ifndef MENU_H
#define MENU_H

#include "Color.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <Factory.h>

class Menu{
    std::istream& inputMethod;
    int turnNumber;
    Product* player1;
    Product* player2;
    Product* board;

public:
    explicit Menu(std::istream& inputMethod = std::cin,int turnNumber = 0):inputMethod(inputMethod), turnNumber(turnNumber){};
    friend std::ostream& operator<<(std::ostream& out, const Menu& m);
    virtual ~Menu()=default;
    //Board declareBoard();
    //Player declarePlayer(Color color);
    void playersMove(Product *player1, Product *player2, Product *board);
    void untilValidMove(Product *player, Product *board);
    void decisionMenu(Player &player1, Player &player2, Board &board);
    bool checkInputMethod() const;

    Menu(const Menu& other):inputMethod(other.inputMethod), turnNumber(other.turnNumber){};
    Menu& operator=(const Menu& other);
};

#endif //MENU_H
