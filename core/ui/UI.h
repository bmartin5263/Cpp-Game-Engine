//
// Created by Brandon on 3/2/22.
//

#ifndef CPP_GAME_ENGINE_UI_H
#define CPP_GAME_ENGINE_UI_H

#include "platform.h"

#ifdef DoDesktop
class GLFWwindow;
#include <unordered_map>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#endif

#include "io/Key.h"
#include "io/Keyboard.h"
#include "io/Mouse.h"
#include <functional>

class UI {
public:
    UI();

    void startup(int width, int height);
    void shutdown();
    void update();
    float time() const;

    Keyboard& keyboard() { return _keyboard; };
    Mouse& mouse() { return _mouse; };

    static int width() { return instance().widthImpl(); };
    static int height() { return instance().heightImpl(); };

    static UI& instance();

#ifdef DoDesktop
    static std::unordered_map<int, Key> GLFW_TO_ENGINE_KEY;
#endif

private:
    friend class Keyboard;
    friend class Graphics;

    int widthImpl() const;
    int heightImpl() const;

    Keyboard _keyboard;
    Mouse _mouse;

    int _width;
    int _height;

#ifdef DoDesktop
    GLFWwindow *glfwWindow;
#endif
};


#endif //CPP_GAME_ENGINE_UI_H
