//
// Created by Horo on 12/6/2024.
//

#ifndef PLACERULE_H
#define PLACERULE_H

#include "Rules.h"
#include "CaptureRule.h"
#include "Color.h"

class PlaceRule : public Rules {

    public:
    explicit PlaceRule(Board &board): Rules(board){}

     ~PlaceRule() override = default;
    void PlaceStone(int lin, int col);
};



#endif //PLACERULE_H
