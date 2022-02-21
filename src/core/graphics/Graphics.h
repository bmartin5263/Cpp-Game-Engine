//
// Created by Brandon on 1/31/22.
//

#ifndef CPP_GAME_ENGINE_GRAPHICS_H
#define CPP_GAME_ENGINE_GRAPHICS_H

#include "PlatformGraphics.h"

class Graphics {
public:
    static bool startup(int width, int height);
    static void shutdown();
    static void update();
    static bool isRunning();

private:
    Graphics() = default;

    static inline PlatformGraphics& instance();
};

#endif //CPP_GAME_ENGINE_GRAPHICS_H