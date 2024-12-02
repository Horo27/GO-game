//
// Created by Horo on 10/22/2024.
//
#pragma once
#include "Color.h"
#include "Game.h"
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <utility>

class Player{
    std::string name;
    Color color; //1 for white 2 for black
    int captures;
    int territoryPoints;

public:
    explicit Player (std::string name = "NULL", const Color color = WHITE, int captures = 0, int territoryPoints = 0):
    name(std::move(name)), color(color), captures(captures), territoryPoints(territoryPoints){};
    ~Player()=default;
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
    std::string getName();

    Player(const Player &other) : name(other.name), color(other.color), captures(other.captures), territoryPoints(other.territoryPoints) {};
    Player& operator=(const Player& other);
};

#endif //PLAYER_Hq
