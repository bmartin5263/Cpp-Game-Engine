//
// Created by Brandon on 2/9/22.
//

#ifndef CPP_GAME_ENGINE_GRAPHICSGL_H
#define CPP_GAME_ENGINE_GRAPHICSGL_H

#include <memory>


#include "../PlatformGraphics.h"
#include "../Polygon.h"
#include "ShaderProgramGl.h"
#include "graphics/MyVertex.h"
#include "MeshGl.h"
#include "TextureGl.h"
#include "../Model.h"

class GLFWwindow;
class GraphicsGl : public PlatformGraphics<GraphicsGl> {
public:

    bool startupImpl(int width, int height);
    void shutdownImpl();
    void updateImpl();
    bool isRunningImpl() const;

private:

    void makeCube(Polygon<MyVertex>* m);
    float width;
    float height;

    GLFWwindow* window{};

    Polygon<MyVertex> trianglePolygon{};
    Polygon<MyVertex> rectanglePolygon{};
    Polygon<MyVertex> cubePolygon{};

    MeshGl<MyVertex> triangleMesh{};
    MeshGl<MyVertex> rectangleMesh{};
    MeshGl<MyVertex> cubeMesh{};

    ShaderProgramGl shaderProgram{};

    TextureGl brickTexture{};
    TextureGl smileyTexture{};

};


#endif //CPP_GAME_ENGINE_GRAPHICSGL_H
