//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_MYVERTEX_H
#define CPP_GAME_ENGINE_MYVERTEX_H
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#include "mygl.hpp"

class MyVertex {
public:
    MyVertex() = default;
    MyVertex(float x, float y, float z) : x(x), y(y), z(z), u(.0f), v(.0f) {}
    MyVertex(float x, float y, float z, float u, float v) : x(x), y(y), z(z), u(u), v(v) {}

    float x = .0f;
    float y = .0f;
    float z = .0f;
    float u = .0f;
    float v = .0f;

    static void enable();
};

#pragma clang diagnostic pop

#endif //CPP_GAME_ENGINE_MYVERTEX_H
