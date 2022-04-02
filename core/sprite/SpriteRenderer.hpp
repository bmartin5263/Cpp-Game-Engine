//
// Created by Brandon on 3/17/22.
//

#ifndef CPP_GAME_ENGINE_SPRITERENDERER_HPP
#define CPP_GAME_ENGINE_SPRITERENDERER_HPP


#include "graphics/Shader.hpp"
#include "graphics/Texture.hpp"
#include "math/Rect.hpp"

class SpriteRenderer {
public:
    ~SpriteRenderer();

    void init();
    void render(Texture &texture,
                    glm::vec2 position,
                    glm::vec2 size = glm::vec2(10.0f, 10.0f),
                    float rotate = 0.0f,
                    glm::vec3 color = glm::vec3(1.0f));
    void render2(Texture &texture);
    void render3(Texture &texture, const Rect& src, const Rect& dst);
private:
    uint quadVAO;
    uint bgVAO;

    void initRenderData();
};


#endif //CPP_GAME_ENGINE_SPRITERENDERER_HPP
