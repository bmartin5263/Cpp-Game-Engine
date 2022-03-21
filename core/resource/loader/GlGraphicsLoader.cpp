//
// Created by Brandon on 3/18/22.
//

#include "graphics/Shader.hpp"
#include "graphics/Texture.hpp"
#include "file/FileSystem.h"
#include "file/utils.hpp"
#include <strtools.hpp>
#include "resource/GraphicsLoader.hpp"

static uint compile(uint vShader, uint fShader) {
    uint id = glCreateProgram();
    glAttachShader(id, vShader);
    glAttachShader(id, fShader);
    glLinkProgram(id);
    assertLinkSuccess(id);
    return id;
}

static void setSampling() {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //    float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    //    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
}

void GraphicsLoader::loadShader(Shader& shader, const char *vShaderFile, const char *fShaderFile,
                                   const char *gShaderFile) {
    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    FileSystem::loadTextFile(vShaderFile, vertexCode);
    FileSystem::loadTextFile(fShaderFile, fragmentCode);
//    FileSystem::loadTextFile(gShaderFile, geometryCode);
    uint vertexShader = createVertexShader(vertexCode.c_str());
    uint fragmentShader = createFragmentShader(fragmentCode.c_str());

    shader.id = compile(vertexShader, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void GraphicsLoader::loadTexture(Texture &texture, const char *file, bool alpha) {
    glGenTextures(1, &texture.id);
    glBindTexture(GL_TEXTURE_2D, texture.id);
    setSampling();
    Image image{};
    FileSystem::loadImage(file, image);
    int rgbFormat = GL_RGB;
    if (alpha) {
        rgbFormat = GL_RGBA;
    }

    if (image.data) {
        glTexImage2D(GL_TEXTURE_2D, 0, rgbFormat, image.width, image.height, 0, rgbFormat, GL_UNSIGNED_BYTE, image.data.get());
        glGenerateMipmap(GL_TEXTURE_2D);
        texture._width = image.width;
        texture._height = image.height;
    }
    else {
        print("Failed to load " + std::string(file));
        assert(false);
    }
}
