//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_TEXTURE_H
#define CPP_GAME_ENGINE_TEXTURE_H


class Texture {
public:
    virtual void init(const char *filename) = 0;
    virtual void use() const = 0;
    virtual ~Texture() = default;
};

class NullTexture : Texture {
    void init(const char *filename) override {}
    void use() const override {}
    ~NullTexture() override = default;
};

#endif //CPP_GAME_ENGINE_TEXTURE_H
