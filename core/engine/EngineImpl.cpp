//
// Created by Brandon on 1/31/22.
//

#include "EngineImpl.h"
#include "tools/StopWatch.h"
#include "globals.hpp"

void EngineImpl::launch(Scene *scene) {
    startSubsystems();
    pushScene(scene);
    doSceneChanges();

    StopWatch sw;
    sw.tick();
    sw.tock();
    sw.time<std::chrono::milliseconds>();

    running = true;

    while (isRunning()) {
        auto currentFrame = _ui.time();
        _deltaTime = currentFrame - _lastTime;
        _lastTime = currentFrame;

        openGlGraphics.clear();
        _ui.update();
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
    return running && openGlGraphics.isRunning();
}

void EngineImpl::startSubsystems() {
    defaultFileSystem.startup("../assets/");
    _ui.startup(375, 667);
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

ResourcesImpl &EngineImpl::resources() {
    return _resources;
}
