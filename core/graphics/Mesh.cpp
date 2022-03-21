//
// Created by Brandon on 3/12/22.
//

#include "Mesh.hpp"

void Mesh::init(MyVertex *vertices, int numVertices, Triangle *triangles, int numTriangles) {
    pVertices.reset(vertices);
    pTriangles.reset(triangles);
    this->numVertices = numVertices;
    this->numTriangles = numTriangles;
    graphicsInit();
}

Triangle *Mesh::triangles() {
    return pTriangles.get();
}

MyVertex *Mesh::vertices() {
    return pVertices.get();
}

long Mesh::trianglesSize() {
    return numTriangles * sizeof(Triangle);
}

long Mesh::verticesSize() {
    return numVertices * sizeof(MyVertex);
}

int Mesh::indices() {
    return numTriangles * 3;
}

Mesh::~Mesh() {
    release();
}
