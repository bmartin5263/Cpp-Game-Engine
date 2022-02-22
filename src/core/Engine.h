//
// Created by Brandon on 1/30/22.
//

#ifndef CPP_GAME_ENGINE_ENGINE_H
#define CPP_GAME_ENGINE_ENGINE_H

#include "file/PlatformFileSystem.h"
#include <../platforms.h>

class Scene;
class EngineImpl;
class Engine {
public:
    static void create();
    static void launch(Scene *scene);
    static void pushScene(Scene *scene);
    static PlatformFileSystem& fileSystem();
    static Graphics& graphics();

private:
    static EngineImpl& instance();

};


#endif //CPP_GAME_ENGINE_ENGINE_H
