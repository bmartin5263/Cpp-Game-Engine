//
// Created by Brandon on 1/30/22.
//

#include "Engine.h"
#include "engine/EngineImpl.h"

EngineImpl &Engine::instance() {
    static EngineImpl engine;
    return engine;
}

void Engine::pushScene(Scene *scene) { instance().pushSceneImpl(scene); }

void Engine::launch(Scene *scene) { instance().launchImpl(scene); }

PlatformFileSystem &Engine::fileSystem() {
    return instance().fileSystem();
}

Graphics &Engine::graphics() {
    return instance().graphics();
}

void Engine::create() {
    instance();
}
