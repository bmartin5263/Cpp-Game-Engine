#include <iostream>
#include "core/Engine.h"
#include "sample/SampleScene.h"

int main(int argc, char* args[]) {
    Engine::create();
    Engine::launch(new SampleScene);
    return 0;
}