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
        Graphics::update();
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
    return running && Graphics::isRunning();
}

void EngineImpl::startSubsystems() {
    FileSystem::startup("../assets/");
    Graphics::startup(640, 480);
}

void EngineImpl::shutdownSubsystems() {
    Graphics::shutdown();
    FileSystem::shutdown();
}