//
// Created by Brandon on 3/17/22.
//

#ifndef CPP_GAME_ENGINE_SCENE2D_HPP
#define CPP_GAME_ENGINE_SCENE2D_HPP

#include "scene/Scene.h"
#include "graphics/system.hpp"
#include "sprite/SpriteRenderer.hpp"

class Scene2d : public Scene {
public:
    Scene2d();
    void initialize() override;
    void update() override;
    void destroy() override;
    ~Scene2d() override;

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

    SpriteRenderer spriteRenderer;

//    Texture* brickTexture{};
    Texture* smileyTexture{};
    Texture* redBg{};
};


#endif //CPP_GAME_ENGINE_SCENE2D_HPP
