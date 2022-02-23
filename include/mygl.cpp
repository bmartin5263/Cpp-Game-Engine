//
// Created by Brandon on 2/14/22.
//

#include "mygl.h"
#include <glad/glad.h>
#include "globals.h"

void assertCompileSuccess(unsigned int shader) {
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        print("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n") << infoLog << std::endl;
        assert(false);
    }
}

void assertLinkSuccess(unsigned int program) {
    int success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        print("ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n") << infoLog << std::endl;
        assert(false);
    }
}

unsigned int createShaderProgram(unsigned int vertexShader, unsigned int fragmentShader) {
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    assertLinkSuccess(shaderProgram);
    return shaderProgram;
}

unsigned int createVertexShader(const char *source) {
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &source, nullptr);
    glCompileShader(vertexShader);
    assertCompileSuccess(vertexShader);
    return vertexShader;
}

unsigned int createFragmentShader(const char *source) {
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &source, nullptr);
    glCompileShader(fragmentShader);
    assertCompileSuccess(fragmentShader);
    return fragmentShader;
}

uint createBuffer() {
    uint id;
    glGenBuffers(1, &id);
    return id;
}

void releaseBuffer(uint id) {
    glDeleteBuffers(1, &id);
}