//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_TEXTURE_HPP
#define CPP_GAME_ENGINE_TEXTURE_HPP

#include <platform.h>

#ifdef DoOpenGl
#include "mygl.hpp"
#include "glad/glad.h"
#else
#error "Unsupported Graphics"
#endif

class Texture {
public:
    PLATFORM void use() const;
    PLATFORM void use(int num) const;
    PLATFORM void release();
    PLATFORM uint width();
    PLATFORM uint height();
    ~Texture();

private:
    friend class GraphicsLoader;
#ifdef DoOpenGl
    uint id = 0;
#endif

    uint _width = 0;
    uint _height = 0;

};

#endif //CPP_GAME_ENGINE_TEXTURE_HPP
