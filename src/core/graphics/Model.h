//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_MODEL_H
#define CPP_GAME_ENGINE_MODEL_H

#include "globals.h"
#include "Mesh.h"
#include "Texture.h"
#include "ShaderProgram.h"

template<typename Vertex>
class Model {
public:
    void init(Mesh<Vertex>* mesh, Texture* texture, ShaderProgram* shaderProgram) {
        this->mesh = mesh;
        this->texture = texture;
        this->shaderProgram = shaderProgram;
    }

    void draw() {
        texture->use();
        shaderProgram->use();
        mesh->draw();
    }

private:
    Mesh<Vertex>* mesh;
    Texture* texture;
    ShaderProgram* shaderProgram;
};

#endif //CPP_GAME_ENGINE_MODEL_H
