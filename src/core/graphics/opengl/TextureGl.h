//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_TEXTUREGL_H
#define CPP_GAME_ENGINE_TEXTUREGL_H

#include <globals.h>
#include "../Texture.h"

class TextureGl : public Texture {
public:
    void init(const char *filename) override;
    void use() const override;
    void use(int num) const;
    void release();

    ~TextureGl() override;

private:
    void setSampling();
    void loadTexture(const char *filename);

    uint id;

};


#endif //CPP_GAME_ENGINE_TEXTUREGL_H
