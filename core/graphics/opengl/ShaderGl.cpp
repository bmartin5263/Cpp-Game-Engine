//
// Created by Brandon on 3/12/22.
//

#include "graphics/Shader.hpp"

void Shader::setMatrix4(const std::string &name, const glm::mat4 &value) {
    use();
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setFloat(const std::string &name, float value) {
    use();
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setInt(const std::string &name, int value) {
    use();
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setBool(const std::string &name, bool value) {
    use();
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void Shader::setVector3f(const std::string &name, glm::vec3 value) {
    use();
    glUniform3f(glGetUniformLocation(id, name.c_str()), value.x, value.y, value.z);
}

void Shader::use() const {
    glUseProgram(id);
}

void Shader::release() {
    glDeleteProgram(id);
    id = 0;
}
