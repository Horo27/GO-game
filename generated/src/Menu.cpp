//
// Created by Horo on 10/26/2024.
//
#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
#include <ostream>

Board Menu::declareBoard() {
    int size;
    std::cout<<"Select the board size: "<<std::endl;
    std::cin>>size;
    Board board(size);
    return board;
}

Player Menu::declarePlayer(std::string color) {
    std::string name;
    std::cout<<"Select the name of the player with the "<< color << " pieces: ";
    std::cin>> name;
    return Player(name, color);
}