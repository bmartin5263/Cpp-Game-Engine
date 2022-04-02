// Include the core Engine interface
#include "core/Engine.h"
#include "core/graphics/Graphics.hpp"
// Include header for a Scene from your own project
#include "sample/SampleScene.h"
#include "sample/Scene2d.hpp"

auto x() {
    return 10;
}

int main() {
    // Start the engine with the given starter scene
    Graphics::initArgs().setClearColor({0.0, 0.2, 0.2});
    Engine::launch(new Scene2d);

    auto z = x;
    z();

    return 0;
}