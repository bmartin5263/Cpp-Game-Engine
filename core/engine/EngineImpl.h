//
// Created by Brandon on 1/31/22.
//

#ifndef CPP_GAME_ENGINE_ENGINEIMPL_H
#define CPP_GAME_ENGINE_ENGINEIMPL_H

#include <deque>
#include <queue>
#include "scene/EngineScene.h"
#include "graphics/Graphics.h"
#include "file/FileSystem.h"
#include "io/Keyboard.h"
#include "ui/UI.h"

typedef std::deque<EngineScene> SceneStack;
typedef std::queue<EngineScene> SceneQueue;

class EngineImpl {
public:
    EngineImpl();

    void launch(Scene *scene);
    void pushScene(Scene *scene);
    void nextFrame();
    void doSceneChanges();
    bool isRunning() const;

    double deltaTime() const;

    FileSystem& fileSystem();
    Graphics& graphics();
    UI& ui();
    Keyboard& keyboard();

private:

    void startSubsystems();
    void shutdownSubsystems();

    // Subsystems
    Graphics openGlGraphics;
    FileSystem defaultFileSystem;
    UI _ui;

    SceneStack sceneStack;
    SceneQueue changeRequests;
    bool running = false;

    double _deltaTime = 0.0;
    double _lastTime = 0.0;

};

#endif //CPP_GAME_ENGINE_ENGINEIMPL_H
