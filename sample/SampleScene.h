//
// Created by Brandon on 1/30/22.
//

#ifndef CPP_GAME_ENGINE_SAMPLESCENE_H
#define CPP_GAME_ENGINE_SAMPLESCENE_H

#include "../core/scene/Scene.h"

class SampleScene : public Scene {
public:
    SampleScene();
    void initialize() override;
    void destroy() override;
    ~SampleScene() override;
};


#endif //CPP_GAME_ENGINE_SAMPLESCENE_H
