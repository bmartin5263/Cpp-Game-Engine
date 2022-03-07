//
// Created by Brandon on 1/30/22.
//

#ifndef CPP_GAME_ENGINE_ENGINESCENE_H
#define CPP_GAME_ENGINE_ENGINESCENE_H

#include <memory>
#include <deque>
#include "Scene.h"

class EngineScene {

    typedef std::deque<EngineScene> SceneStack;

public:

    explicit EngineScene(Scene *scene);
    EngineScene(EngineScene&& scene) = default;
    EngineScene& operator=(EngineScene&& scene) = default;
    virtual ~EngineScene();

    [[nodiscard]] bool isClosing() const;
    void doClose(SceneStack &stack);
    void doOpen(SceneStack &stack);
    void update();

private:
    std::unique_ptr<Scene> scene;
    bool closing;
};


#endif //CPP_GAME_ENGINE_ENGINESCENE_H
