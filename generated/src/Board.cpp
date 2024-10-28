//
// Created by Horo on 10/22/2024.
//
#include "../include/Board.h"
#include <vector>
#include <iostream>
#include <functional>

void Board::displayBoard(){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Board::placeStone(int x, int y, Color color) {
    if(board[x][y] == EMPTY) {
        board[x][y] = color;

        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        Color opponentColor = (color == WHITE ? BLACK : WHITE);

        for(auto dir:directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if(nx >= 0 && nx < size && ny >= 0 && ny < size)
                if(isCaptured(nx,ny,opponentColor))
                    removeStones(nx,ny,opponentColor);
        }
    }
}

void Board::clearBoard() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = EMPTY;
        }
    }
}

bool Board::isCaptured(int x, int y, Color color) {
    std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));
    const std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool hasLiberties = false;

    std::function<void(int, int)> dfs = [&](int cx, int cy) {
        visited[cx][cy] = true;

        for (auto dir : directions) {
            const int nx = cx + dir.first;
            const int ny = cy + dir.second;

            if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                if (board[nx][ny] == EMPTY) {
                    hasLiberties = true;
                } else if (board[nx][ny] == color && !visited[nx][ny]) {
                    dfs(nx, ny);
                }
            }
        }
    };

    dfs(x,y);

    return !hasLiberties;
}

void Board::removeStones(int x, int y, Color color) {
    std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));
    const std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    std::function<void(int, int)> dfs = [&](const int cx, const int cy) {
        board[cx][cy] = EMPTY;
        visited[cx][cy] = true;

        for (auto dir : directions) {
            const int nx = cx + dir.first;
            const int ny = cy + dir.second;

            ///conditie daca vecinul este de aceeasi culoare si nevizitat
            if (nx >= 0 && nx < size && ny >= 0 && ny < size && board[nx][ny] == color && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    };

    dfs(x,y);
}