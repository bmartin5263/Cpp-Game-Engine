//
// Created by Brandon on 2/19/22.
//

#ifndef CPP_GAME_ENGINE_PLATFORMMESH_H
#define CPP_GAME_ENGINE_PLATFORMMESH_H

#include "mygl.h"
#include "globals.h"
#include "Polygon.h"

template<class Derived, class Vertex>
class PlatformMesh {
public:

    void init(Polygon<Vertex> *polygon) {
        return static_cast<Derived*>(this)->initImpl(polygon);
    }

    void draw() {
        static_cast<Derived*>(this)->drawImpl();
    }

    Polygon<Vertex>& polygon() {
        return static_cast<Derived*>(this)->polygonImpl();
    }

};


#endif //CPP_GAME_ENGINE_PLATFORMMESH_H
