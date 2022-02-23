//
// Created by Brandon on 2/19/22.
//

#ifndef CPP_GAME_ENGINE_MESH_H
#define CPP_GAME_ENGINE_MESH_H

#include <../platform.h>
#include "globals.h"
#include "Polygon.h"

#ifdef DoOpenGl
#include "mygl.h"
#include "glad/glad.h"
#elif NO
using Graphics = PlatformGraphics<VulkanTraits>;
#endif

template<class V>
class Mesh {
public:
#ifdef DoOpenGl
    void init(Polygon<V>& polygon) {
        _polygon = &polygon;

        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, polygon.trianglesSize(), polygon.triangles(), GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, polygon.verticesSize(), polygon.vertices(), GL_STATIC_DRAW);

        V::enable();

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    };

    void draw() {
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, _polygon->indices(), GL_UNSIGNED_INT, nullptr);
    };

    void release() {
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
    }
#endif

    Polygon<V>& polygon() {
        return _polygon;
    };

    ~Mesh() {
        release();
    }

private:
    Polygon<V>* _polygon;

#ifdef DoOpenGl
    uint vbo = 0;
    uint ebo = 0;
    uint vao = 0;
#endif

};


#endif //CPP_GAME_ENGINE_MESH_H
