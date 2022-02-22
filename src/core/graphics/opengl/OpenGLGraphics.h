//
// Created by Brandon on 2/9/22.
//

#ifndef CPP_GAME_ENGINE_OPENGLGRAPHICS_H
#define CPP_GAME_ENGINE_OPENGLGRAPHICS_H

#include <memory>


#include "../PlatformGraphics.h"
#include "../MeshDataStatic.h"
#include "ShaderProgramGl.h"
#include "graphics/MyVertex.h"
#include "MeshGl.h"
#include "FatMeshGl.h"
#include "TextureGl.h"
#include "../Model.h"

class GLFWwindow;
class OpenGLGraphics : public PlatformGraphics<OpenGLGraphics> {
public:

    bool startupImpl(int width, int height);
    void shutdownImpl();
    void updateImpl();

    bool isRunningImpl() const;

private:

    void makeCube(MeshData<MyVertex>* m);
    float width;
    float height;

    GLFWwindow* window{};

    MeshDataStatic<MyVertex, 3, 1> triangleMeshData{};
    MeshDataStatic<MyVertex, 4, 2> rectangleMeshData{};
    MeshDataStatic<MyVertex, 36, 12> cubeMeshData{};

    MeshGl<MyVertex> triangleMesh{};
    MeshGl<MyVertex> rectangleMesh{};
    FatMeshGl<MyVertex> cubeMesh{};

    ShaderProgramGl shaderProgram{};

    TextureGl brickTexture{};
    TextureGl smileyTexture{};

};


#endif //CPP_GAME_ENGINE_OPENGLGRAPHICS_H
