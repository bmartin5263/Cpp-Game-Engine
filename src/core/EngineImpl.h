//
// Created by Brandon on 1/31/22.
//

#ifndef CPP_GAME_ENGINE_ENGINEIMPL_H
#define CPP_GAME_ENGINE_ENGINEIMPL_H

#include <deque>
#include <queue>
#include "scene/EngineScene.h"

typedef std::deque<EngineScene> SceneStack;
typedef std::queue<EngineScene> SceneQueue;

class EngineImpl {
public:

    void launchImpl(Scene *scene);
    void pushSceneImpl(Scene *scene);
    void nextFrame();
    void doSceneChanges();
    bool isRunning() const;

private:

    void startSubsystems();
    void shutdownSubsystems();

    SceneStack sceneStack;
    SceneQueue changeRequests;
    bool running = false;

};

#endif //CPP_GAME_ENGINE_ENGINEIMPL_H
