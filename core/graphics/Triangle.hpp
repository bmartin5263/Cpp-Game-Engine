//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_TRIANGLE_HPP
#define CPP_GAME_ENGINE_TRIANGLE_HPP

struct Triangle {
    Triangle() = default;
    Triangle(int _i0, int _i1, int _i2): i0(_i0), i1(_i1), i2(_i2) {}

    int& operator[] (int index) {
        int* i = reinterpret_cast<int*>(this);
        return *(i + index);
    }

    int i0;
    int i1;
    int i2;
};

#endif //CPP_GAME_ENGINE_TRIANGLE_HPP
