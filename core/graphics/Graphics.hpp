//
// Created by Brandon on 1/31/22.
//

#ifndef CPP_GAME_ENGINE_GRAPHICS_HPP
#define CPP_GAME_ENGINE_GRAPHICS_HPP

/**
 * Simulate conditional compilation
 */

#include "platform.h"

class Graphics {
public:
    void startup();
    void shutdown();
    void update();

    bool isRunningImpl() const;

    static bool isRunning() { return instance().isRunningImpl(); };

    static Graphics& instance();

};

#endif //CPP_GAME_ENGINE_GRAPHICS_HPP
