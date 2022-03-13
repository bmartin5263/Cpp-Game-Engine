//
// Created by Brandon on 3/12/22.
//

#include "Mesh.hpp"

void Mesh::init(int numVertices, int numTriangles) {
    pVertices = std::make_unique<MyVertex[]>(numVertices);
    pTriangles = std::make_unique<Triangle[]>(numTriangles);
    this->numVertices = numVertices;
    this->numTriangles = numTriangles;
}

void Mesh::init(MyVertex *vertices, int numVertices, Triangle *triangles, int numTriangles) {
    pVertices.reset(vertices);
    pTriangles.reset(triangles);
    this->numVertices = numVertices;
    this->numTriangles = numTriangles;
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
