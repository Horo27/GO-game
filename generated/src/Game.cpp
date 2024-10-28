//
// Created by Horo on 10/26/2024.
//
#include "Game.h"

#include <bits/atomic_base.h>

#include "Player.h"

void Game::changeState(bool state) {
    this->gameState = state;
}

bool Game::currState() {
    return gameState;
}
