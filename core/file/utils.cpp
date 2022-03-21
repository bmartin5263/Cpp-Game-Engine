//
// Created by Brandon on 2/21/22.
//

#include "utils.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void ImageDeleter::operator()(byte *data) {
    stbi_image_free(data);
}

void Image::load(const char* path) {
//    stbi_set_flip_vertically_on_load(true);
    data.reset(stbi_load(path, &width, &height, &nrChannels, 0));
}
