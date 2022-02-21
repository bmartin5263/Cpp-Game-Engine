//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_PLATFORMGRAPHICS_H
#define CPP_GAME_ENGINE_PLATFORMGRAPHICS_H


class PlatformGraphics {
public:
    virtual bool startup(int width, int height) = 0;
    virtual void shutdown() = 0;
    virtual void update() = 0;
    virtual bool isRunning() = 0;
    virtual ~PlatformGraphics() = default;
};


#endif //CPP_GAME_ENGINE_PLATFORMGRAPHICS_H
