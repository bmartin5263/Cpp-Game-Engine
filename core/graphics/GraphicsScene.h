//
// Created by Brandon on 2/21/22.
//

#ifndef CPP_GAME_ENGINE_GRAPHICSSCENE_H
#define CPP_GAME_ENGINE_GRAPHICSSCENE_H


#include "MyVertex.h"
#include "Texture.h"
#include "Shader.h"
#include "Polygon.h"
#include "Mesh.h"
#include "Graphics.h"
#include "Camera.h"

class GraphicsScene {
public:
    void init();
    void update();

private:
    Camera camera{glm::vec3(0.0f, 0.0f, 3.0f)};
    glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);
    bool firstMouse = true;
    float yaw   = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
    float pitch =  0.0f;
    float lastX =  800.0f / 2.0;
    float lastY =  600.0 / 2.0;
    float fov   =  45.0f;

    Polygon<MyVertex> trianglePolygon{};
    Polygon<MyVertex> rectanglePolygon{};
    Polygon<MyVertex> cubePolygon{};

    Mesh<MyVertex> triangleMesh{};
    Mesh<MyVertex> rectangleMesh{};
    Mesh<MyVertex> cubeMesh{};

    Shader<MyVertex> shaderProgram{};

    Texture brickTexture{};
    Texture smileyTexture{};
};


#endif //CPP_GAME_ENGINE_GRAPHICSSCENE_H