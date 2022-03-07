//
// Created by Brandon on 1/30/22.
//

#ifndef CPP_GAME_ENGINE_SCENE_H
#define CPP_GAME_ENGINE_SCENE_H


#include <iostream>

class Scene {
public:

    virtual void initialize() {}
    virtual void destroy() {}
    virtual void update();

    virtual ~Scene() = default;
};


#endif //CPP_GAME_ENGINE_SCENE_H
