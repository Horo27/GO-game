//
// Created by Horo on 10/26/2024.
//
#include "Game.h"

void Game::changeState(bool state) {
    this->gameState = state;
}


bool Game::currState() {
    return gameState;
}
