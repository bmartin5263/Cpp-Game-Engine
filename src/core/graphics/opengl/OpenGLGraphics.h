//
// Created by Brandon on 2/9/22.
//

#ifndef CPP_GAME_ENGINE_OPENGLGRAPHICS_H
#define CPP_GAME_ENGINE_OPENGLGRAPHICS_H

#include <memory>


#include "../Graphics.h"
#include "../MeshDataStatic.h"
#include "ShaderProgramGl.h"
#include "MyVertex.h"
#include "MeshGl.h"
#include "TextureGl.h"
#include "../Model.h"

class GLFWwindow;
class OpenGLGraphics : public PlatformGraphics {
public:

    bool startup(int width, int height) override;
    void shutdown() override;
    void update() override;

    bool isRunning() override;

private:

    Model<MyVertex> triangle;
    Model<MyVertex> rectangle;

    GLFWwindow* window{};
    MeshDataStatic<MyVertex, 3, 1> triangleMeshData{};
    MeshDataStatic<MyVertex, 4, 2> rectangleMeshData{};
    MeshGl<MyVertex> triangleMesh{};
    MeshGl<MyVertex> rectangleMesh{};
    ShaderProgramGl shaderProgram{};
    TextureGl brickTexture{};
    TextureGl smileyTexture{};

};


#endif //CPP_GAME_ENGINE_OPENGLGRAPHICS_H
