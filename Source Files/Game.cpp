//
// Created by Horo on 10/26/2024.
//
#include "../Headers/Game.h"

bool Game::getState() {
    return gameState;
}

void Game::changeState(bool state) {
    gameState = state;
}


