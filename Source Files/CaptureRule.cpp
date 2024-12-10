//
// Created by Horo on 12/6/2024.
//
#include "../Headers/CaptureRule.h"
#include <functional>

bool CaptureRule::basicRule(int lin, int col) {
    std::vector<std::vector<bool>> visited(board.size, std::vector<bool>(board.size, false));
    const std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool hasLiberties = false;

    std::function<void(int, int)> dfs = [&](int cx, int cy) {
        visited[cx][cy] = true;

        for (auto dir : directions) {
            const int nx = cx + dir.first;
            const int ny = cy + dir.second;

            if (nx >= 0 && nx < board.size && ny >= 0 && ny < board.size) {
                if (board.board[nx][ny] == EMPTY) {
                    hasLiberties = true;
                } else if (board.board[nx][ny] == color && !visited[nx][ny]) {
                    dfs(nx, ny);
                }
            }
        }
    };

    dfs(lin,col);

    return !hasLiberties;
}

void CaptureRule::removeStones(int lin, int col) {

    std::vector<std::vector<bool>> visited(board.size, std::vector<bool>(board.size, false));
    const std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    std::function<void(int, int)> dfs = [&](const int cx, const int cy) {
        board.board[cx][cy] = EMPTY;
        visited[cx][cy] = true;

        for (auto dir : directions) {
            const int nx = cx + dir.first;
            const int ny = cy + dir.second;

            ///conditie daca vecinul este de aceeasi culoare si nevizitat
            if (nx >= 0 && nx < board.size && ny >= 0 && ny < board.size && board.board[nx][ny] == color && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    };

    dfs(lin,col);
}
