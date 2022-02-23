//
// Created by Brandon on 1/31/22.
//

#ifndef CPP_GAME_ENGINE_GRAPHICS_H
#define CPP_GAME_ENGINE_GRAPHICS_H

/**
 * Simulate conditional compilation
 */

#include "../platform.h"

#ifdef DoOpenGl
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#elif NO
using Graphics = PlatformGraphics<VulkanTraits>;
#endif

class Graphics {
public:
    void startup(int width, int height);
    void shutdown();
    void update();

    bool isRunningImpl() const;
    float widthImpl() const;
    float heightImpl() const;

    static bool isRunning() { return instance().isRunningImpl(); };
    static float width() { return instance().widthImpl(); };
    static float height() { return instance().heightImpl(); };

    static Graphics& instance();

private:
    float _width = 0.0f;
    float _height = 0.0f;

#ifdef DoOpenGl
    GLFWwindow *window{};
#endif

};

#endif //CPP_GAME_ENGINE_GRAPHICS_H
