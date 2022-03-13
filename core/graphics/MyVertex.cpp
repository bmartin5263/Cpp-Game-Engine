//
// Created by Brandon on 2/22/22.
//

#include "MyVertex.hpp"
#include <glad/glad.h>

void MyVertex::enable() {
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MyVertex), nullptr);
    glEnableVertexAttribArray(0);

    // texture attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(MyVertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}