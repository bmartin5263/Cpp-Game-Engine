//
// Created by Brandon on 2/19/22.
//

#ifndef CPP_GAME_ENGINE_MESH_HPP
#define CPP_GAME_ENGINE_MESH_HPP

#include "platform.h"
#include "globals.hpp"
#include "Triangle.hpp"

#ifdef DoOpenGl
#include "mygl.hpp"
#include "glad/glad.h"
#endif

#include "MyVertex.hpp"

class Mesh {
public:

    void init(int numVertices, int numTriangles);
    void init(MyVertex* vertices, int numVertices, Triangle* triangles, int numTriangles);
    Triangle* triangles();
    MyVertex* vertices();
    long trianglesSize();
    long verticesSize();
    int indices();

    ~Mesh();

    ABSTRACT void draw();
    ABSTRACT void release();
    ABSTRACT void graphicsInit();

private:

    std::unique_ptr<MyVertex[]> pVertices{nullptr};
    std::unique_ptr<Triangle[]> pTriangles{nullptr};
    uint numVertices = 0;
    uint numTriangles = 0;

#ifdef DoOpenGl
    uint vbo = 0;
    uint ebo = 0;
    uint vao = 0;
#endif

};


#endif //CPP_GAME_ENGINE_MESH_HPP
