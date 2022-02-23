//
// Created by Brandon on 1/31/22.
//

#include <../platform.h>

#ifdef DoOpenGl

#include "globals.h"
#include "graphics/Graphics.h"
#include "Engine.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    UNUSED(window)
    glViewport(0, 0, width, height);
}

void Graphics::startup(int width, int height) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    this->_width = (float) width;
    this->_height = (float) height;

    window = glfwCreateWindow(width, height, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        print("Failed to create GLFW window");
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        print("Failed to initialize GLAD");
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, 800, 600);
    glEnable(GL_DEPTH_TEST);
}

void Graphics::shutdown() {
    glfwTerminate();
}

void Graphics::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool Graphics::isRunningImpl() const {
    return !glfwWindowShouldClose(window);
}

Graphics &Graphics::instance() {
    return Engine::graphics();
}

#endif