// Include the core Engine interface
#include "core/Engine.h"
// Include header for a Scene from your own project
#include "sample/SampleScene.h"

int main() {
    // Start the engine with the given starter scene
    Engine::launch(new SampleScene);
    return 0;
}