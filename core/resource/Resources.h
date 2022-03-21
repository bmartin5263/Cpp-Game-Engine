//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_RESOURCES_H
#define CPP_GAME_ENGINE_RESOURCES_H

#include "utils.hpp"

class ResourcesImpl;
class Shader;
class Texture;
class Resources {
public:
    static Shader* loadShader(Identifier id, const char *vShaderFile, const char *fShaderFile, const char *gShaderFile);
    static Texture* loadTexture(Identifier id, const char *file, bool alpha);

    template<class T>
    static T* get(Identifier id);

    template<>
    Shader* get(Identifier id) {
        return getShader(id);
    }

    template<>
    Texture* get(Identifier id) {
        return getTexture(id);
    }

private:
    static Shader* getShader(Identifier id);
    static Texture* getTexture(Identifier id);
    static ResourcesImpl& instance();
};


#endif //CPP_GAME_ENGINE_RESOURCES_H
