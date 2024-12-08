//
// Created by Horo on 12/6/2024.
//
#pragma once
#include "Board.h"

#ifndef RULES_H
#define RULES_H

class Rules {
    protected:
    Board &board;
    static Color color;

    public:
    explicit Rules(Board &board): board(board){}
    virtual ~Rules() = default;
    virtual bool basicRule(int lin, int col);

    friend class CaptureRule;
    friend class PlaceRule;

    static void setColor(const Color other) {color = other;}
};

#endif //RULES_H
