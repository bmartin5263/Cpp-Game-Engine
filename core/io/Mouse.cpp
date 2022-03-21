//
// Created by Brandon on 3/6/22.
//

#include "Mouse.h"
#include "Engine.h"
#include "ui/UI.h"

Mouse &Mouse::instance() {
    return Engine::ui().mouse();
}

void Mouse::setPositionImpl(float x, float y) {
    xPos = x;
    yPos = y;
}

void Mouse::getPositionImpl(float &x, float &y) const {
    x = xPos;
    y = yPos;
}

void Mouse::setScrollImpl(float x, float y) {
    xScroll = x;
    yScroll = y;
}

void Mouse::getScrollImpl(float &x, float &y) const {
    x = xScroll;
    y = yScroll;
}
