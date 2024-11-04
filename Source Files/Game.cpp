//
// Created by Horo on 10/26/2024.
//
#include "../Headers/Game.h"

#include <bits/atomic_base.h>

std::ostream& operator<<(std::ostream& out, const Game& game) {
    out<<"Game State: "<<game.gameState<<std::endl;
    return out;
}

void Game::changeState(bool state) {
    this->gameState = state;
}
