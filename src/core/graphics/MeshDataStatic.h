#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "modernize-use-nodiscard"
//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_MESHDATASTATIC_H
#define CPP_GAME_ENGINE_MESHDATASTATIC_H

#include "globals.h"
#include "MeshData.h"
#include "Triangle.h"

template<class Vertex, ulong V, ulong T>
class MeshDataStatic : public MeshData<Vertex> {
public:
    Triangle *triangles() override {
        return _triangles;
    }

    Vertex *vertices() override {
        return _vertices;
    }

    long trianglesSize() const override {
        return sizeof(_triangles);
    }

    long verticesSize() const override {
        return sizeof(_vertices);
    }

    int trianglesLength() const override {
        return T * 3;
    }

    Vertex _vertices[V] {};
    Triangle _triangles[T] {};
};

#endif //CPP_GAME_ENGINE_MESHDATASTATIC_H

#pragma clang diagnostic pop