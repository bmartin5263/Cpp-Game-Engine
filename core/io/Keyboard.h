//
// Created by Brandon on 3/2/22.
//

#ifndef CPP_GAME_ENGINE_KEYBOARD_H
#define CPP_GAME_ENGINE_KEYBOARD_H

#include "platform.h"
#include "Key.h"

#include <unordered_set>

typedef void(*FunctionPointer)(Key);

/*
 * Interface to the keyboard hardware device, if one exists
 */
class Keyboard {
public:
    bool isKeyPressedImpl(Key key);
    void pressKeyImpl(Key key);
    void releaseKeyImpl(Key key);
    void clear();

    static bool isKeyPressed(Key key) { return instance().isKeyPressedImpl(key); };
    static void pressKey(Key key) { instance().pressKeyImpl(key); };
    static void releaseKey(Key key) { instance().releaseKeyImpl(key); };
    constexpr static FunctionPointer dispatchMap[3] { releaseKey, pressKey, pressKey };

    static Keyboard& instance();

private:
     std::unordered_set<Key> pressed;
};


#endif //CPP_GAME_ENGINE_KEYBOARD_H
