//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_TEXTURE_H
#define CPP_GAME_ENGINE_TEXTURE_H

#include <platform.h>

#ifdef DoOpenGl
#include "mygl.hpp"
#include "glad/glad.h"
#else
#error "Unsupported Graphics"
#endif

class Texture {
public:
    void init(const char *filename);
    void use() const;
    void use(int num) const;
    void release();

    ~Texture();

private:
#ifdef DoOpenGl
    void setSampling();
    void loadTexture(const char *filename);
    uint id;
#endif
};

#endif //CPP_GAME_ENGINE_TEXTURE_H
