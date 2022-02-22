//
// Created by Brandon on 2/21/22.
//

#ifndef CPP_GAME_ENGINE_GRAPHICSSCENE_H
#define CPP_GAME_ENGINE_GRAPHICSSCENE_H


#include "../platforms.h"

class GraphicsScene {
public:
    void init();
    void update();

private:
    Polygon<MyVertex> trianglePolygon{};
    Polygon<MyVertex> rectanglePolygon{};
    Polygon<MyVertex> cubePolygon{};

    Mesh<MyVertex> triangleMesh{};
    Mesh<MyVertex> rectangleMesh{};

//    PlatformShader shaderProgram{};
//
//    Texture brickTexture{};
//    Texture smileyTexture{};

};


#endif //CPP_GAME_ENGINE_GRAPHICSSCENE_H
