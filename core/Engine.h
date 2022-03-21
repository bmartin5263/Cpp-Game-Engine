//
// Created by Brandon on 1/30/22.
//

#ifndef CPP_GAME_ENGINE_ENGINE_H
#define CPP_GAME_ENGINE_ENGINE_H

class FileSystem;
class Graphics;
class Keyboard;
class UI;
class ResourcesImpl;
class Scene;
class EngineImpl;
class Engine {
public:
    static void launch(Scene *scene);
    static void pushScene(Scene *scene);

    static double deltaTime();

    static FileSystem& fileSystem();
    static Graphics& graphics();
    static Keyboard& keyboard();
    static UI& ui();
    static ResourcesImpl& resources();

private:
    static EngineImpl& instance();

};


#endif //CPP_GAME_ENGINE_ENGINE_H
