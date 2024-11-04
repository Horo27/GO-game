//
// Created by Horo on 10/28/2024.
//
#pragma once

#ifndef COLOR_H
#define COLOR_H
#include <unordered_map>
#include <string>

enum Color {
    EMPTY = 0,  // Empty space on the board
    WHITE = 1,  // Black stone
    BLACK = 2   // White stone
};

inline std::unordered_map<Color, std::string> colorMap = {
    {EMPTY, "EMPTY"},
    {BLACK, "BLACK"},
    {WHITE, "WHITE"}
};


inline std::string colorToString(Color color) {
    return colorMap[color];
}
#endif //COLOR_H
