//
// Created by Horo on 12/6/2024.
//

#ifndef CAPTURERULE_H
#define CAPTURERULE_H

#include "Rules.h"

class CaptureRule : public Rules{

    public:
    explicit CaptureRule(Board &board): Rules(board){};

    bool basicRule(int lin, int col) override;
    void removeStones(int lin, int col);
};

#endif //CAPTURERULE_H
