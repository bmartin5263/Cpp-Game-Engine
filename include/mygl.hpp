//
// Created by Brandon on 2/14/22.
//

#ifndef CPP_GAME_ENGINE_MYGL_HPP
#define CPP_GAME_ENGINE_MYGL_HPP

#define GL_SILENCE_DEPRECATION

#include <iostream>

void assertCompileSuccess(uint shader);
void assertLinkSuccess(uint program);
uint createShaderProgram(uint vertexShader, uint fragmentShader);
uint createVertexShader(const char *source);
uint createFragmentShader(const char *source);
uint createBuffer();
void releaseBuffer(uint id);

#endif //CPP_GAME_ENGINE_MYGL_HPP
