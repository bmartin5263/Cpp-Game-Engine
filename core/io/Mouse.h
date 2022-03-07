//
// Created by Brandon on 3/6/22.
//

#ifndef CPP_GAME_ENGINE_MOUSE_H
#define CPP_GAME_ENGINE_MOUSE_H


/*
 * Interface to the keyboard hardware device, if one exists
 */
class Mouse {
public:
    void setPositionImpl(float x, float y);
    void getPositionImpl(float &x, float &y) const;

    void setScrollImpl(float x, float y);
    void getScrollImpl(float &x, float &y) const;

    static void setPosition(float x, float y) { instance().setPositionImpl(x, y); };
    static void getPosition(float &x, float &y) { instance().getPositionImpl(x, y); };

    static void setScroll(float x, float y) { instance().setScrollImpl(x, y); };
    static void getScroll(float &x, float &y) { instance().getScrollImpl(x, y); };

    static Mouse& instance();

private:
    float xPos;
    float yPos;
    float xScroll;
    float yScroll;
};


#endif //CPP_GAME_ENGINE_MOUSE_H
