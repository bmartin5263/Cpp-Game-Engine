//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_MESHGL_H
#define CPP_GAME_ENGINE_MESHGL_H

#include "../PlatformMesh.h"

template<class V>
class MeshGl : public PlatformMesh<MeshGl<V>, V> {
public:
    void initImpl(Polygon<V> *v) {
        polygon = v;

        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, polygon->trianglesSize(), polygon->triangles(), GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, polygon->verticesSize(), polygon->vertices(), GL_STATIC_DRAW);

        V::enable();

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    };

    void release() {
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
    };

    void drawImpl() {
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, polygon->indices(), GL_UNSIGNED_INT, nullptr);
    };

    Polygon<V>& polygonImpl() {
        return polygon;
    }

    ~MeshGl() {
        release();
    }

private:
    uint vbo = 0;
    uint ebo = 0;
    uint vao = 0;
    Polygon<V>* polygon;
};

#endif //CPP_GAME_ENGINE_MESHGL_H
