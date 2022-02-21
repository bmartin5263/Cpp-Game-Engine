#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"
//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_MESHDATA_H
#define CPP_GAME_ENGINE_MESHDATA_H

#include "globals.h"

class Triangle;
template<class Vertex>
class MeshData {
public:
    virtual Triangle* triangles() = 0;
    virtual Vertex* vertices() = 0;
    virtual long trianglesSize() const = 0;
    virtual long verticesSize() const = 0;
    virtual int trianglesLength() const = 0;
    virtual ~MeshData() = default;

};

#endif //CPP_GAME_ENGINE_MESHDATA_H

#pragma clang diagnostic pop