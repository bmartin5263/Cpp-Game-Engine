////
//// Created by Brandon on 2/20/22.
////
//
//#ifndef CPP_GAME_ENGINE_MODEL_H
//#define CPP_GAME_ENGINE_MODEL_H
//
//#include "globals.h"
//#include "Mesh.h"
//#include "Texture.h"
//#include "Shader.h"
//
//template<typename V>
//class Model {
//public:
//    void graphicsInit(Mesh<V>* mesh, Texture* texture, Shader* shaderProgram) {
//        this->mesh = mesh;
//        this->texture = texture;
//        this->shaderProgram = shaderProgram;
//    }
//
//    void draw() {
//        texture->use();
//        shaderProgram->use();
//        mesh->draw();
//    }
//
//private:
//    Mesh<V>* mesh;
//    Texture* texture;
//    Shader* shaderProgram;
//};
//
//#endif //CPP_GAME_ENGINE_MODEL_H
