//
// Created by Brandon on 1/31/22.
//

#include "EngineImpl.h"
#include "tools/StopWatch.h"
#include "graphics/Graphics.h"
#include "globals.h"
#include "FileSystem.h"

void EngineImpl::launchImpl(Scene *scene) {
    startSubsystems();
    pushSceneImpl(scene);

    StopWatch sw;
    sw.tick();
    sw.tock();
    sw.time<std::chrono::milliseconds>();

    running = true;
    while (isRunning()) {
        openGlGraphics.update();
    }

    shutdownSubsystems();
}

void EngineImpl::pushSceneImpl(Scene *scene) {
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
    openGlGraphics.startup(800, 600);
}

void EngineImpl::shutdownSubsystems() {
    openGlGraphics.shutdown();
    defaultFileSystem.shutdown();
}

PlatformFileSystem &EngineImpl::fileSystem() {
    return defaultFileSystem;
}

OpenGLGraphics &EngineImpl::graphics() {
    return openGlGraphics;
}

EngineImpl::EngineImpl() {
    print("EngineImpl()");
}
