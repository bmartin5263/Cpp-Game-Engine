//
// Created by Brandon on 2/20/22.
//

#include "platform.h"

#ifdef DoOpenGl

#include "globals.hpp"

#include "graphics/Texture.hpp"
#include "glad/glad.h"

void Texture::release() {
    glDeleteTextures(1, &id);
}

void Texture::use() const {
    use(GL_TEXTURE0);
}

void Texture::use(int num) const {
    glActiveTexture(num);
    glBindTexture(GL_TEXTURE_2D, id);
}

#endif