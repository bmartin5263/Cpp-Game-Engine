//
// Created by Brandon on 1/31/22.
//

#include "platform.h"

#ifdef DoOpenGl

#include "globals.hpp"
#include "graphics/Graphics.h"
#include "Engine.h"

void Graphics::startup() {
    glViewport(0, 0, UI::width(), UI::height());
    glEnable(GL_DEPTH_TEST);
}

void Graphics::shutdown() {
}

void Graphics::update() {
    glfwSwapBuffers(UI::instance().glfwWindow);
}

bool Graphics::isRunningImpl() const {
    return !glfwWindowShouldClose(UI::instance().glfwWindow);
}

Graphics &Graphics::instance() {
    return Engine::graphics();
}

#endif