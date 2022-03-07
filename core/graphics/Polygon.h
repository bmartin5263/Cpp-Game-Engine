#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"
//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_MESHDATA_H
#define CPP_GAME_ENGINE_MESHDATA_H

#include <memory>

#include "globals.h"
#include "Triangle.h"

template<class V>
class Polygon {
public:

    void init(int numVertices, int numTriangles) {
        pVertices = std::make_unique<V[]>(numVertices);
        pTriangles = std::make_unique<Triangle[]>(numTriangles);
        this->numVertices = numVertices;
        this->numTriangles = numTriangles;
    }

    void init(V* vertices, int numVertices, Triangle* triangles, int numTriangles) {
        pVertices.reset(vertices);
        pTriangles.reset(triangles);
        this->numVertices = numVertices;
        this->numTriangles = numTriangles;
    }

    Triangle* triangles() {
        return pTriangles.get();
    }

    V* vertices() {
        return pVertices.get();
    }

    long trianglesSize() {
        return numTriangles * sizeof(Triangle);
    }

    long verticesSize() {
        return numVertices * sizeof(V);
    }

    int indices() {
        return numTriangles * 3;
    }

    std::unique_ptr<V[]> pVertices{nullptr};
    std::unique_ptr<Triangle[]> pTriangles{nullptr};
    uint numVertices = 0;
    uint numTriangles = 0;

};

#endif //CPP_GAME_ENGINE_MESHDATA_H

#pragma clang diagnostic pop