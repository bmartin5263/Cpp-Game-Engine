//
// Created by Brandon on 3/12/22.
//

#include "graphics/Shader.hpp"

void Shader::init(const char *vShader, const char *fShader) {
    std::string vertexCode;
    std::string fragmentCode;
    FileSystem::loadTextFile(vShader, vertexCode);
    FileSystem::loadTextFile(fShader, fragmentCode);
    uint vertexShader = createVertexShader(vertexCode.c_str());
    uint fragmentShader = createFragmentShader(fragmentCode.c_str());

    id = compile(vertexShader, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::setMatrix4(const std::string &name, const glm::mat4 &value) {
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setFloat(const std::string &name, float value) {
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setInt(const std::string &name, int value) {
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setBool(const std::string &name, bool value) {
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void Shader::use() const {
    glUseProgram(id);
}

void Shader::release() {
    glDeleteProgram(id);
    id = 0;
}

uint Shader::compile(uint vShader, uint fShader) {
    uint id = glCreateProgram();
    glAttachShader(id, vShader);
    glAttachShader(id, fShader);
    glLinkProgram(id);
    assertLinkSuccess(id);
    return id;
}