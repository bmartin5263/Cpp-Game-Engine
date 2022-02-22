//
// Created by Brandon on 2/20/22.
//

#include "TextureGl.h"
#include "mygl.h"
#include "../../file/FileSystemUtil.h"
#include "FileSystem.h"
#include <strtools.h>

void TextureGl::init(const char *filename) {
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    setSampling();
    loadTexture(filename);
}

void TextureGl::release() {
    glDeleteTextures(1, &id);
}

void TextureGl::use() const {
    use(GL_TEXTURE0);
}

void TextureGl::use(int num) const {
    glActiveTexture(num);
    glBindTexture(GL_TEXTURE_2D, id);
}

TextureGl::~TextureGl() {
    release();
}

void TextureGl::setSampling() {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //    float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    //    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
}

void TextureGl::loadTexture(const char *filename) {
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
