//
// Created by Brandon on 1/30/22.
//

#ifndef CPP_GAME_ENGINE_ENGINE_H
#define CPP_GAME_ENGINE_ENGINE_H

#include <deque>
#include <queue>
#include "scene/Scene.h"

class EngineImpl;
class Engine {
public:
    static void launch(Scene *scene);
    static void pushScene(Scene *scene);

private:
    static EngineImpl& instance();

};


#endif //CPP_GAME_ENGINE_ENGINE_H
