//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_RESOURCESIMPL_HPP
#define CPP_GAME_ENGINE_RESOURCESIMPL_HPP

#include <string>
#include <unordered_map>

#include "graphics/Texture.hpp"
#include "graphics/Shader.hpp"
#include "GraphicsLoader.hpp"

class ResourcesImpl {
public:
    Shader* loadShader(Identifier id, const char *vShaderFile, const char *fShaderFile, const char *gShaderFile);
    Shader* getShader(Identifier id);

    Texture* loadTexture(Identifier id, const char *file, bool alpha);
    Texture* getTexture(Identifier id);

    void clear();

    template<class T>
    T* get(Identifier id) { assert(false); };

    template<>
    Shader* get(Identifier id) {
        return getShader(id);
    }

    template<>
    Texture* get(Identifier id) {
        return getTexture(id);
    }

private:
    std::unordered_map<Identifier, Shader> shaders;
    std::unordered_map<Identifier, Texture> textures;

    GraphicsLoader graphicsLoader;
};


#endif //CPP_GAME_ENGINE_RESOURCESIMPL_HPP
