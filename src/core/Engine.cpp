//
// Created by Brandon on 1/30/22.
//

#include "Engine.h"
#include "EngineImpl.h"

EngineImpl &Engine::instance() {
    static EngineImpl engine;
    return engine;
}

void Engine::pushScene(Scene *scene) { instance().pushSceneImpl(scene); }

void Engine::launch(Scene *scene) { instance().launchImpl(scene); }
