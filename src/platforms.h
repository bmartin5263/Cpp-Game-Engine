//
// Created by Brandon on 2/21/22.
//

#ifndef CPP_GAME_ENGINE_PLATFORMS_H
#define CPP_GAME_ENGINE_PLATFORMS_H

#include "graphics/opengl/GraphicsGl.h"

#define DoOpenGl

#ifdef DoOpenGl
using Graphics = GraphicsGl;
template<class V>
using Mesh = MeshGl<V>;
#elif NO
using Graphics = PlatformGraphics<VulkanTraits>;
#endif


#endif //CPP_GAME_ENGINE_PLATFORMS_H
