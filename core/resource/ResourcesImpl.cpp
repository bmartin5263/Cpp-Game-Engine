//
// Created by Brandon on 2/20/22.
//

#include "ResourcesImpl.hpp"

//void *ResourcesImpl::loadShader(Shader &shader, std::string id, const char *vShaderFile, const char *fShaderFile,
//                                const char *gShaderFile) {
//    return nullptr;
//}
//
//void *ResourcesImpl::getShader(std::string id, Shader &shader) {
//    return nullptr;
//}
//
//Texture *ResourcesImpl::loadTexture(const char *file, bool alpha, std::string id) {
//    return nullptr;
//}
//
//Texture *ResourcesImpl::getTexture(const std::string& id, Texture& texture) {
//    auto it = textures.find(id);
//    if (it != textures.end()) {
//        texture =
//    }
//    return &textures[id];
//}

void ResourcesImpl::clear() {
    textures.clear();
    shaders.clear();
}

Shader* ResourcesImpl::loadShader(Identifier id, const char *vShaderFile, const char *fShaderFile, const char *gShaderFile) {
    auto it = shaders.find(id);
    if (it == shaders.end()) {
        shaders[id] = {};
        auto& shader = shaders[id];
        graphicsLoader.loadShader(shader, vShaderFile, fShaderFile, gShaderFile);
        return &shader;
    }
    return &it->second;
}

Shader* ResourcesImpl::getShader(Identifier id) {
    auto it = shaders.find(id);
    if (it == shaders.end()) {
        return nullptr;
    }
    return &shaders[id];
}

Texture* ResourcesImpl::loadTexture(Identifier id, const char *file, bool alpha) {
    auto it = textures.find(id);
    if (it == textures.end()) {
        textures[id] = {};
        auto& texture = textures[id];
        graphicsLoader.loadTexture(texture, file, alpha);
        return &texture;
    }
    return &it->second;
}

Texture* ResourcesImpl::getTexture(Identifier id) {
    auto it = textures.find(id);
    if (it == textures.end()) {
        return nullptr;
    }
    return &textures[id];
}