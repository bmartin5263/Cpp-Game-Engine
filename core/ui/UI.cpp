//
// Created by Brandon on 3/2/22.
//

#include "UI.h"
#include "Engine.h"

UI &UI::instance() {
    return Engine::ui();
}

int UI::widthImpl() const {
    return _width;
}

int UI::heightImpl() const {
    return _height;
}

