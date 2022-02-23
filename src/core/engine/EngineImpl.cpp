//
// Created by Brandon on 1/31/22.
//

#include "EngineImpl.h"
#include "tools/StopWatch.h"
#include "globals.h"
#include "FileSystem.h"
#include <graphics/GraphicsScene.h>

void EngineImpl::launchImpl(Scene *scene) {
    startSubsystems();
    pushSceneImpl(scene);

    StopWatch sw;
    sw.tick();
    sw.tock();
    sw.time<std::chrono::milliseconds>();

    running = true;

    GraphicsScene gs;
    gs.init();
    while (isRunning()) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        gs.update();
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

FileSystem &EngineImpl::fileSystem() {
    return defaultFileSystem;
}

Graphics &EngineImpl::graphics() {
    return openGlGraphics;
}

EngineImpl::EngineImpl() {
    print("EngineImpl()");
}
