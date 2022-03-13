//
// Created by Brandon on 3/2/22.
//

#include "platform.h"

#ifdef DoDesktop
#include "ui/UI.h"
#include "globals.hpp"

std::unordered_map<int, Key> UI::GLFW_TO_ENGINE_KEY;

void framebuffer_size_callback_2(GLFWwindow* window, int width, int height){
    UNUSED(window)
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double x, double y)
{
    Mouse::setPosition(static_cast<float>(x), static_cast<float>(y));
}

void scroll_callback(GLFWwindow* window, double x, double y)
{
    Mouse::setScroll(static_cast<float>(x), static_cast<float>(y));
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Keyboard::DISPATCH_MAP[action](UI::GLFW_TO_ENGINE_KEY[key]);
}

UI::UI() {
    GLFW_TO_ENGINE_KEY = {
            {GLFW_KEY_A,             Key::A},
            {GLFW_KEY_B,             Key::B},
            {GLFW_KEY_C,             Key::C},
            {GLFW_KEY_D,             Key::D},
            {GLFW_KEY_E,             Key::E},
            {GLFW_KEY_F,             Key::F},
            {GLFW_KEY_G,             Key::G},
            {GLFW_KEY_H,             Key::H},
            {GLFW_KEY_I,             Key::I},
            {GLFW_KEY_J,             Key::J},
            {GLFW_KEY_K,             Key::K},
            {GLFW_KEY_L,             Key::L},
            {GLFW_KEY_M,             Key::M},
            {GLFW_KEY_N,             Key::N},
            {GLFW_KEY_O,             Key::O},
            {GLFW_KEY_P,             Key::P},
            {GLFW_KEY_Q,             Key::Q},
            {GLFW_KEY_R,             Key::R},
            {GLFW_KEY_S,             Key::S},
            {GLFW_KEY_T,             Key::T},
            {GLFW_KEY_U,             Key::U},
            {GLFW_KEY_V,             Key::V},
            {GLFW_KEY_W,             Key::W},
            {GLFW_KEY_X,             Key::X},
            {GLFW_KEY_Y,             Key::Y},
            {GLFW_KEY_Z,             Key::Z},
            {GLFW_KEY_SPACE,         Key::SPACE},
            {GLFW_KEY_UP,            Key::UP},
            {GLFW_KEY_DOWN,          Key::DOWN},
            {GLFW_KEY_LEFT,          Key::LEFT},
            {GLFW_KEY_RIGHT,         Key::RIGHT},
            {GLFW_KEY_PERIOD,        Key::PERIOD},
            {GLFW_KEY_SEMICOLON,     Key::SEMICOLON},
            {GLFW_KEY_APOSTROPHE,    Key::APOSTROPHE},
            {GLFW_KEY_LEFT_BRACKET,  Key::L_BRACKET},
            {GLFW_KEY_RIGHT_BRACKET, Key::R_BRACKET}
    };
}

void UI::startup(int width, int height) {
    this->_width = width;
    this->_height = height;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

//    this->_width = (float) width;
//    this->_height = (float) height;

    glfwWindow = glfwCreateWindow(width, height, "LearnOpenGL", nullptr, nullptr);
    if (glfwWindow == nullptr) {
        print("Failed to create GLFW window");
        glfwTerminate();
    }

    glfwMakeContextCurrent(glfwWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        print("Failed to initialize GLAD");
    }

    glfwSetFramebufferSizeCallback(glfwWindow, framebuffer_size_callback_2);
    glfwSetKeyCallback(glfwWindow, key_callback);
    glfwSetCursorPosCallback(glfwWindow, mouse_callback);
    glfwSetScrollCallback(glfwWindow, scroll_callback);
    glfwGetTime();
}

void UI::shutdown() {
    glfwDestroyWindow(glfwWindow);
    glfwTerminate();
}

float UI::time() const {
    return static_cast<float>(glfwGetTime());
}

void UI::update() {
//    _keyboard.clear();
    glfwPollEvents();
}

#endif
