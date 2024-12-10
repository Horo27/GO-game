//
// Created by Horo on 12/6/2024.
//
#include "../Headers/PlaceRule.h"
#include <memory>

void PlaceRule::PlaceStone(int lin, int col) {

    std::shared_ptr<Rules> capturePtr = std::make_shared<CaptureRule>(board);
    std::shared_ptr<CaptureRule> specificDerivedRule = std::dynamic_pointer_cast<CaptureRule>(capturePtr);


    if(board.board[lin][col] == EMPTY) {
        board.board[lin][col] = color;

        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        Color opponentColor = (color == WHITE ? BLACK : WHITE);

        CaptureRule::setColor(opponentColor);

        for(auto dir:directions) {
            int nx = lin + dir.first;
            int ny = col + dir.second;

            if(nx >= 0 && nx < board.size && ny >= 0 && ny < board.size)
                if(specificDerivedRule->basicRule(nx,ny))
                    specificDerivedRule->removeStones(nx,ny);
        }
        CaptureRule::setColor(color);
    }
}
