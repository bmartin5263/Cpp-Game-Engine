//
// Created by Brandon on 1/30/22.
//

#include "EngineScene.h"
#include "Scene.h"

EngineScene::EngineScene(Scene *scene): scene(scene), closing(false) {
    std::cout << "new EngineScene()\n";
}

bool EngineScene::isClosing() const {
    return closing;
}

void EngineScene::doClose(EngineScene::SceneStack &stack) {
    scene->destroy();
    stack.pop_front();
}

void EngineScene::doOpen(EngineScene::SceneStack &stack) {
    scene->initialize();
}

EngineScene::~EngineScene() {
    std::cout << "~EngineScene()\n";
}

void EngineScene::update() {
    scene->update();
}
