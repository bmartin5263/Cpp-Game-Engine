//
// Created by Brandon on 2/19/22.
//

#ifndef CPP_GAME_ENGINE_MESH_H
#define CPP_GAME_ENGINE_MESH_H

#include "mygl.h"
#include "globals.h"
#include "MeshData.h"

template<class Vertex>
class Mesh {
public:
    virtual void init(MeshData<Vertex> *v) = 0;
    virtual void draw() = 0;
    virtual ~Mesh() = default;

    void setMeshData(MeshData<Vertex> *data) {
        this->data.reset(data);
    }

    MeshData<Vertex>& getMeshData() {
        return *data.get();
    }

private:
    std::unique_ptr<MeshData<Vertex>> data{};

};


#endif //CPP_GAME_ENGINE_MESH_H
