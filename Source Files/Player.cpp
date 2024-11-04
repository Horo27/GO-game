//
// Created by Horo on 10/23/2024.
//
#include "../Headers/Player.h"
#include "../Headers/Board.h"
#include <iostream>
#include <string>

std::ostream& operator<<(std::ostream& out, const Player& player) {

    out<<"Name: "<<player.name<<std::endl;
    out<<"Color: "<<colorToString(player.color)<<std::endl;
    out<<"Captures: "<<player.captures<<std::endl;
    out<<"Territory: "<<player.territoryPoints<<std::endl;

    return out;
}

std::string Player::getName() {
    return this->name;
}
