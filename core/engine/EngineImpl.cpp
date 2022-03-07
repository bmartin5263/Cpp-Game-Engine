//
// Created by Brandon on 1/31/22.
//

#include "EngineImpl.h"
#include "tools/StopWatch.h"
#include "globals.hpp"
#include <graphics/GraphicsScene.h>

void EngineImpl::launch(Scene *scene) {
    startSubsystems();
    pushScene(scene);
    doSceneChanges();

    StopWatch sw;
    sw.tick();
    sw.tock();
    sw.time<std::chrono::milliseconds>();

    running = true;
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    GraphicsScene gs;
    gs.init();
    while (isRunning()) {
        auto currentFrame = _ui.time();
        _deltaTime = currentFrame - _lastTime;
        _lastTime = currentFrame;

        _ui.update();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        gs.update();
        sceneStack.front().update();
        openGlGraphics.update();
    }

    shutdownSubsystems();
}

void EngineImpl::pushScene(Scene *scene) {
    changeRequests.emplace(scene);
}

void EngineImpl::nextFrame() {
    print("EngineImpl::nextFrame()");
    doSceneChanges();
    sceneStack.front().update();
}

void EngineImpl::doSceneChanges() {
    while (!sceneStack.empty() && sceneStack.front().isClosing()) {
        auto& currentScene = sceneStack.front();
        currentScene.doClose(sceneStack);
    }
    while (!changeRequests.empty()) {
        sceneStack.push_front(std::move(changeRequests.front()));
        sceneStack.front().doOpen(sceneStack);
        changeRequests.pop();
    }
}

bool EngineImpl::isRunning() const {
    return running && openGlGraphics.isRunningImpl();
}

void EngineImpl::startSubsystems() {
    defaultFileSystem.startup("../assets/");
    _ui.startup(800, 600);
    openGlGraphics.startup();
}

void EngineImpl::shutdownSubsystems() {
    openGlGraphics.shutdown();
    defaultFileSystem.shutdown();
}

FileSystem &EngineImpl::fileSystem() {
    return defaultFileSystem;
}

Graphics &EngineImpl::graphics() {
    return openGlGraphics;
}

EngineImpl::EngineImpl() {
    print("EngineImpl()");
}

UI &EngineImpl::ui() {
    return _ui;
}

Keyboard &EngineImpl::keyboard() {
    return _ui.keyboard();
}

double EngineImpl::deltaTime() const {
    return _deltaTime;
}
