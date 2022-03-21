//
// Created by Brandon on 3/20/22.
//

#ifndef CPP_GAME_ENGINE_GRAPHICSARGS_HPP
#define CPP_GAME_ENGINE_GRAPHICSARGS_HPP

struct GraphicsArgs {
    Vec4f clearColor{1.0f, 0.0f, 0.0f, 1.0f};

    GraphicsArgs& setClearColor(const Vec4f& v) {
        clearColor = v;
        return *this;
    }
};

#endif //CPP_GAME_ENGINE_GRAPHICSARGS_HPP
