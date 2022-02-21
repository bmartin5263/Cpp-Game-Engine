//
// Created by Brandon on 1/30/22.
//

#include <iostream>
#include "SampleScene.h"

SampleScene::SampleScene() {
    std::cout << "new SampleScene()\n";
}

void SampleScene::initialize() {
    std::cout << "SampleScene::initialize()\n";
}

void SampleScene::destroy() {
    std::cout << "SampleScene::destroy()\n";
}

SampleScene::~SampleScene() {
    std::cout << "~SampleScene()\n";
}

