//
// Created by Brandon on 3/2/22.
//

#include "Keyboard.h"
#include "Engine.h"
#include "ui/UI.h"

Keyboard &Keyboard::instance() {
    return Engine::ui().keyboard();
}

void Keyboard::pressKeyImpl(Key key) {
    pressed.insert(key);
}

bool Keyboard::isKeyPressedImpl(Key key) {
    return pressed.find(key) != pressed.end();
}

void Keyboard::clear() {
    pressed.clear();
}

void Keyboard::releaseKeyImpl(Key key) {
    pressed.erase(key);
}
