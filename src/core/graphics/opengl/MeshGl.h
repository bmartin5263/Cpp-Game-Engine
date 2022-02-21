//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_MESHGL_H
#define CPP_GAME_ENGINE_MESHGL_H

#include "../Mesh.h"

template<class Vertex>
class MeshGl : public Mesh<Vertex> {
public:
    void init(MeshData<Vertex> *v) {
        this->setMeshData(v);

        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->getMeshData().trianglesSize(), this->getMeshData().triangles(), GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, this->getMeshData().verticesSize(), this->getMeshData().vertices(), GL_STATIC_DRAW);

        Vertex::enable();

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    };

    void release() {
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
    };

    void draw() {
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, this->getMeshData().trianglesLength(), GL_UNSIGNED_INT, nullptr);
    };

    ~MeshGl() {
        release();
    }

private:
    uint vbo = 0;
    uint ebo = 0;
    uint vao = 0;
};

#endif //CPP_GAME_ENGINE_MESHGL_H
