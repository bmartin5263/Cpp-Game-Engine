//
// Created by Brandon on 3/17/22.
//

#include "SpriteRenderer.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ResourceId.hpp"
#include "resource/Resources.h"

SpriteRenderer::~SpriteRenderer()
{
    glDeleteVertexArrays(1, &this->quadVAO);
}

void SpriteRenderer::render(Texture &texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color)
{
    // prepare transformations
    auto shader = Resources::get<Shader>(int(ShaderId::SPRITE_SHADER));
    shader->use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));

    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    model = glm::scale(model, glm::vec3(size, 1.0f));

    shader->setMatrix4("model", model);
    shader->setVector3f("spriteColor", color);

    glActiveTexture(GL_TEXTURE0);
    texture.use();

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRenderer::render2(Texture &texture)
{
    // prepare transformations
    auto position = glm::vec2(0.0f,0.0f);
    auto color = glm::vec3(1.0f);
    auto size = glm::vec2(texture.width(), texture.height());
    auto shader = Resources::get<Shader>(int(ShaderId::SPRITE_SHADER));
    shader->use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));
    model = glm::scale(model, glm::vec3(size, 1.0f));

    shader->setMatrix4("model", model);
    shader->setVector3f("spriteColor", color);

    glActiveTexture(GL_TEXTURE0);
    texture.use();

    glBindVertexArray(this->bgVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRenderer::initRenderData()
{
    // configure VAO/VBO
    unsigned int VBO;
    float vertices[] = {
            // pos      // tex
            0.0f, 1.0f, 0.0f, .5f,
            1.0f, 0.0f, .5f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f,

            0.0f, 1.0f, 0.0f, .5f,
            1.0f, 1.0f, .5f, .5f,
            1.0f, 0.0f, .5f, 0.0f
    };

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    unsigned int VBO2;
    float vertices2[] = {
            // pos      // tex
            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f,

            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &this->bgVAO);
    glGenBuffers(1, &VBO2);

    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

    glBindVertexArray(this->bgVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void SpriteRenderer::init() {
    this->initRenderData();
}
