//
// Created by Horo on 10/28/2024.
//

#include <unordered_map>
#include <string>

#ifndef COLOR_H
#define COLOR_H
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
