//
// Created by Horo on 1/8/2025.
//
#include <utility>

#include "../Headers/Factory.h"

std::ostream& operator<<(std::ostream& out, const PlayerProduct& player) {

    out<<"Name: "<<player.name<<std::endl;
    out<<"Color: "<<colorToString(player.color)<<std::endl;
    out<<"Captures: "<<player.captures<<std::endl;
    out<<"Territory: "<<player.territoryPoints<<std::endl;

    return out;
}

std::string PlayerProduct::getName() {
    return this->name;
}

void PlayerProduct::setNameColor(std::string name, Color color) {
    this->name = std::move(name);
    this->color = color;
}




/*PlayerProduct &PlayerProduct::operator=(const PlayerProduct &other) {
    if(this==&other)
        return *this;
    this->name = other.name;
    this->color = other.color;
    this->captures = other.captures;
    this->territoryPoints = other.territoryPoints;
    return *this;
}*/