//
// Created by Brandon on 2/21/22.
//

#ifndef CPP_GAME_ENGINE_PLATFORMS_H
#define CPP_GAME_ENGINE_PLATFORMS_H

#include "graphics/opengl/OpenGLGraphics.h"

#define YES

#ifdef YES
using Graphics = OpenGLGraphics;
#elif NO
using Graphics = PlatformGraphics<VulkanTraits>;
#endif

#endif //CPP_GAME_ENGINE_PLATFORMS_H
