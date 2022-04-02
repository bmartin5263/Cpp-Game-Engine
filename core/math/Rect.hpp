//
// Created by Brandon on 3/20/22.
//

#ifndef CPP_GAME_ENGINE_RECT_HPP
#define CPP_GAME_ENGINE_RECT_HPP


struct Rect {
    Rect() = default;
    Rect(int x, int y, int width, int height): x(x), y(y), width(width), height(height) {};

    int x, y, width, height;
};


#endif //CPP_GAME_ENGINE_RECT_HPP
