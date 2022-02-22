////
//// Created by Brandon on 2/20/22.
////
//
//#ifndef CPP_GAME_ENGINE_MODEL_H
//#define CPP_GAME_ENGINE_MODEL_H
//
//#include "globals.h"
//#include "PlatformMesh.h"
//#include "Texture.h"
//#include "PlatformShader.h"
//
//template<typename V>
//class Model {
//public:
//    void init(PlatformMesh<V>* mesh, Texture* texture, PlatformShader* shaderProgram) {
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
//    PlatformMesh<V>* mesh;
//    Texture* texture;
//    PlatformShader* shaderProgram;
//};
//
//#endif //CPP_GAME_ENGINE_MODEL_H
