//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_MYVERTEX_H
#define CPP_GAME_ENGINE_MYVERTEX_H
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#include "mygl.h"

class MyVertex {
public:
    MyVertex() = default;
    MyVertex(float x, float y, float z, float r, float g, float b) : x(x), y(y), z(z), r(r), g(g), b(b) {}
    MyVertex(float x, float y, float z, float r, float g, float b, float u, float v) : x(x), y(y), z(z), r(r), g(g), b(b), u(u), v(v) {}

    float x = .0f;
    float y = .0f;
    float z = .0f;
    float r = .0f;
    float g = .0f;
    float b = .0f;
    float u = .0f;
    float v = .0f;

    static void enable() {
        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MyVertex), nullptr);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(MyVertex), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(MyVertex), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }
};

#pragma clang diagnostic pop

#endif //CPP_GAME_ENGINE_MYVERTEX_H
