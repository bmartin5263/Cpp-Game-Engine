//
// Created by Brandon on 2/20/22.
//

#include "Resources.h"
#include "Engine.h"
#include "ResourcesImpl.hpp"

ResourcesImpl &Resources::instance() {
    return Engine::resources();
}

Shader* Resources::loadShader(Identifier id, const char *vShaderFile, const char *fShaderFile, const char *gShaderFile) {
    return instance().loadShader(id, vShaderFile, fShaderFile, gShaderFile);
}

Shader* Resources::getShader(Identifier id) {
    return instance().getShader(id);
}

Texture* Resources::loadTexture(Identifier id, const char *file, bool alpha) {
    return instance().loadTexture(id, file, alpha);
}

Texture* Resources::getTexture(Identifier id) {
    return instance().getTexture(id);
}