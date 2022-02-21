//
// Created by Brandon on 1/31/22.
//

#include "Graphics.h"
#include "opengl/OpenGLGraphics.h"

PlatformGraphics &Graphics::instance() {
    static OpenGLGraphics graphics;
    return graphics;
}

bool Graphics::startup(int width, int height) {
    return instance().startup(width, height);
}

void Graphics::shutdown() {
    instance().shutdown();
}

void Graphics::update() {
    instance().update();
}

bool Graphics::isRunning() {
    return instance().isRunning();
}
