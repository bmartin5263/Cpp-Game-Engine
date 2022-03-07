//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_SHADER_H
#define CPP_GAME_ENGINE_SHADER_H

#include "glm/detail/type_mat.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Engine.h"
#include <fstream>
#include <sstream>
#include <globals.hpp>

#include "platform.h"
#ifdef DoOpenGl
#include "mygl.hpp"
#include "glad/glad.h"
#else
#error "Unsupported Graphics"
#endif

template<class V>
class Shader {
public:
#ifdef DoOpenGl
    void init(const char *vShader, const char *fShader) {
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

    void use() const {
        glUseProgram(id);
    }

    void setBool(const std::string &name, bool value) {
        glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
    }

    void setInt(const std::string &name, int value) {
        glUniform1i(glGetUniformLocation(id, name.c_str()), value);
    }

    void setFloat(const std::string &name, float value) {
        glUniform1f(glGetUniformLocation(id, name.c_str()), value);
    }

    void setMatrix4(const std::string &name, const glm::mat4& value) {
        glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
    }

    void release() {
        glDeleteProgram(id);
        id = 0;
    }
#endif

    ~Shader() {
        release();
    }

private:
#ifdef DoOpenGl
    uint id = 0;

    static void readFiles(const char *vPath, const char *fPath, std::string &vertexCode, std::string &fragmentCode) {
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
    };

    static uint compile(uint vShader, uint fShader) {
        uint id = glCreateProgram();
        glAttachShader(id, vShader);
        glAttachShader(id, fShader);
        glLinkProgram(id);
        assertLinkSuccess(id);
        return id;
    };
#endif
};

#endif //CPP_GAME_ENGINE_SHADERGL_H
