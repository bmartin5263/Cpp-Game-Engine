//
// Created by Brandon on 1/30/22.
//

#include "Engine.h"
#include "engine/EngineImpl.h"

EngineImpl &Engine::instance() {
    static EngineImpl engine;   // the singleton from which all other Engine systems belong to
    return engine;
}

void Engine::pushScene(Scene *scene) { instance().pushScene(scene); }

void Engine::launch(Scene *scene) { instance().launch(scene); }

FileSystem &Engine::fileSystem() {
    return instance().fileSystem();
}

Graphics &Engine::graphics() {
    return instance().graphics();
}

Keyboard &Engine::keyboard() {
    return instance().keyboard();
}

UI &Engine::ui() {
    return instance().ui();
}

double Engine::deltaTime() {
    return instance().deltaTime();
}

ResourcesImpl &Engine::resources() {
    return instance().resources();
}
