//
// Created by Brandon on 1/31/22.
//

#ifndef CPP_GAME_ENGINE_GRAPHICS_HPP
#define CPP_GAME_ENGINE_GRAPHICS_HPP

/**
 * Simulate conditional compilation
 */

#include "platform.h"
#include "math/Vec4f.h"
#include "GraphicsArgs.hpp"

class Graphics {
public:
    void startup();
    void shutdown();
    void update();
    void clear();
    bool isRunning() const;

    static Graphics& instance();
    static GraphicsArgs& initArgs() {
        static GraphicsArgs gp;
        return gp;
    };

private:

};

#endif //CPP_GAME_ENGINE_GRAPHICS_HPP
