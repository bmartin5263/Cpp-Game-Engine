//
// Created by Brandon on 2/22/22.
//

#include "Texture.hpp"

uint Texture::width() {
    return _width;
}

uint Texture::height() {
    return _height;
}

Texture::~Texture() {
    release();
}