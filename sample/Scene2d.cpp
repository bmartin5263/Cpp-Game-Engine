//
// Created by Brandon on 1/30/22.
//

#include <iostream>
#include "Scene2d.hpp"
#include "ResourceId.hpp"
#include "resource/Resources.h"
#include "ui/UI.h"

Scene2d::Scene2d() {
    std::cout << "new Scene2d()\n";
}

void Scene2d::initialize() {
    smileyTexture = Resources::loadTexture(int(TextureId::SMILEY), "images/awesomeface.png", true);
    redBg = Resources::loadTexture(int(TextureId::BG), "images/redbg.png", true);
    glm::mat4 projection = glm::ortho(
            0.0f, static_cast<float>(UI::width()), static_cast<float>(UI::height()), 0.0f, -1.0f, 1.0f
    );
    auto shader = Resources::loadShader(
            int(ShaderId::SPRITE_SHADER),
            "shaders/2d/vshader.glsl",
            "shaders/2d/fshader.glsl",
            "shaders/2d/gshader.glsl"
    );
    shader->setInt("image", 0);
    shader->setMatrix4("projection", projection);
    spriteRenderer.init();
}

void Scene2d::destroy() {
    std::cout << "Scene2d::destroy()\n";
}

Scene2d::~Scene2d() {
    std::cout << "~Scene2d()\n";
}

void Scene2d::update() {
    auto deltaTime = Engine::deltaTime();
    spriteRenderer.render2(*redBg);
//    spriteRenderer.render2(*smileyTexture);
    spriteRenderer.render(*smileyTexture,         glm::vec2(20.0f, 20.0f), glm::vec2(300.0f, 400.0f));

}