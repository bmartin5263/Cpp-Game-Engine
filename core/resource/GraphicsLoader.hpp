//
// Created by Brandon on 3/18/22.
//

#ifndef CPP_GAME_ENGINE_GRAPHICSLOADER_HPP
#define CPP_GAME_ENGINE_GRAPHICSLOADER_HPP

#include "resource/utils.hpp"
#include "platform.h"

class Shader;
class Texture;
class GraphicsLoader {
public:
    void loadShader(Shader& shader, const char *vShaderFile, const char *fShaderFile, const char *gShaderFile);
    void loadTexture(Texture& texture, const char *file, bool alpha);

private:

};

#endif //CPP_GAME_ENGINE_GRAPHICSLOADER_HPP
