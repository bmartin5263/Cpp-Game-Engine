//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_PLATFORMGRAPHICS_H
#define CPP_GAME_ENGINE_PLATFORMGRAPHICS_H

template <class T>
class PlatformGraphics {
public:
    bool startup(int width, int height) {
        return static_cast<T*>(this)->startupImpl(width, height);
    };
    void shutdown() {
        static_cast<T*>(this)->shutdownImpl();
    };
    void update() {
        static_cast<T*>(this)->updateImpl();
    };
    bool isRunning() const {
        return static_cast<const T*>(this)->isRunningImpl();
    };
};


#endif //CPP_GAME_ENGINE_PLATFORMGRAPHICS_H
