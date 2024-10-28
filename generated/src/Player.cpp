//
// Created by Horo on 10/23/2024.
//
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <string.h>

//Player::Player(std::string name, int caputres, int teritoryPoints):
//name(name), caputres(caputres), teritoryPoints(teritoryPoints){}

void Player::displayStats() {
    std::cout <<"Numele:" << this->name << std::endl;
    std::cout <<"Culoarea:" << colorToString(color) << std::endl;
    std::cout <<"Caputres:" << this->caputres << std::endl;
    std::cout <<"Territory:" << this->teritoryPoints << std::endl;
    std::cout <<std::endl;
}

/*
void Player::placeStone(Board &board, int x, int y) {
    //board.placeStone(x,y,this->color == WHITE ? 0 : 1);
    board.placeStone(x,y,color);
}*/

std::string Player::getName() {
    return this->name;
}
