//
// Created by Brandon on 1/31/22.
//

#include "platform.h"

#ifdef DoOpenGl

#include "graphics/Graphics.hpp"
#include "Engine.h"
#include "ui/UI.h"

void Graphics::startup() {
    glViewport(0, 0, UI::width(), UI::height());
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    auto& clearColor = Graphics::initArgs().clearColor;
    glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
}

void Graphics::shutdown() {
}

void Graphics::update() {
    glfwSwapBuffers(UI::instance().glfwWindow);
}

bool Graphics::isRunning() const {
    return !glfwWindowShouldClose(UI::instance().glfwWindow);
}

Graphics &Graphics::instance() {
    return Engine::graphics();
}

void Graphics::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

#endif