//
// Created by Brandon on 2/14/22.
//

#include <fstream>
#include <sstream>
#include "ShaderProgramGl.h"
#include "mygl.h"
#include "globals.h"
#include "../../FileSystem.h"

void ShaderProgramGl::init(const char *vPath, const char *fPath) {
    std::string vertexCode = FileSystem::loadTextFile(vPath);
    std::string fragmentCode = FileSystem::loadTextFile(fPath);
    uint vertexShader = createVertexShader(vertexCode.c_str());
    uint fragmentShader = createFragmentShader(fragmentCode.c_str());

    id = compile(vertexShader, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

ShaderProgramGl::~ShaderProgramGl() {
    release();
}

void ShaderProgramGl::use() const {
    glUseProgram(id);
}

uint ShaderProgramGl::compile(uint vShader, uint fShader) {
    uint id = glCreateProgram();
    glAttachShader(id, vShader);
    glAttachShader(id, fShader);
    glLinkProgram(id);
    assertLinkSuccess(id);
    return id;
}

void ShaderProgramGl::readFiles(const char *vPath, const char *fPath, std::string &vertexCode, std::string &fragmentCode) {
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        // open file
        vShaderFile.open(vPath);
        fShaderFile.open(fPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode   = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure &e) {
        print("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
        assert(false);
    }
}

void ShaderProgramGl::release() {
    glDeleteProgram(id);
    id = 0;
}

void ShaderProgramGl::setBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void ShaderProgramGl::setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void ShaderProgramGl::setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}