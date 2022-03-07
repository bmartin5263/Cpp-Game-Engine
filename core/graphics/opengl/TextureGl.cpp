//
// Created by Brandon on 2/20/22.
//

#include "platform.h"

#ifdef DoOpenGl

#include "globals.h"

#include "../Texture.h"
#include "../../file/FileSystemUtil.h"
#include "glad/glad.h"
#include "file/FileSystem.h"
#include <strtools.h>

void Texture::init(const char *filename) {
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    setSampling();
    loadTexture(filename);
}

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

void Texture::setSampling() {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //    float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    //    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
}

void Texture::loadTexture(const char *filename) {
    Image imagee{};
    FileSystem::loadImage(filename, imagee);
    int rgbFormat = GL_RGB;
    if (hasEnding(filename, ".png")) {
        rgbFormat = GL_RGBA;
    }

    if (imagee.data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imagee.width, imagee.height, 0, rgbFormat, GL_UNSIGNED_BYTE, imagee.data.get());
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        print("Failed to load brickTexture");
        assert(false);
    }
}

#endif