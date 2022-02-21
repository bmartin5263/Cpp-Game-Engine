//
// Created by Brandon on 2/9/22.
//

#include "OpenGLGraphics.h"
#include <globals.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void makeTriangle(MeshData<MyVertex>* m) {
                                // POS              // COLOR            // TEXTURE
    m->vertices()[0] = MyVertex(-.5f, -.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f);  // bottom left
    m->vertices()[1] = MyVertex(0.5f, -.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f);  // bottom right
    m->vertices()[2] = MyVertex(0.0f, 0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.5f, 1.0f);  // top

    m->triangles()[0][0] = 2;
    m->triangles()[0][1] = 0;
    m->triangles()[0][2] = 1;
}

void makeRectangle(MeshData<MyVertex>* m) {
                                // POS              // COLOR            // TEXTURE
    m->vertices()[0] = MyVertex(0.5f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f);  // top right
    m->vertices()[1] = MyVertex(0.5f, -.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f);  // bottom right
    m->vertices()[2] = MyVertex(-.5f, -.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f);  // bottom left
    m->vertices()[3] = MyVertex(-.5f, 0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f);  // top left

    m->triangles()[0][0] = 0;
    m->triangles()[0][1] = 1;
    m->triangles()[0][2] = 3;
    m->triangles()[1][0] = 1;
    m->triangles()[1][1] = 2;
    m->triangles()[1][2] = 3;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    UNUSED(window)
    glViewport(0, 0, width, height);
}

bool OpenGLGraphics::startup(int width, int height) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        print("Failed to create GLFW window");
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        print("Failed to initialize GLAD");
        return false;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, 800, 600);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    makeTriangle(&triangleMeshData);
    makeRectangle(&rectangleMeshData);

    triangleMesh.init(&triangleMeshData);
    rectangleMesh.init(&rectangleMeshData);

    brickTexture.init("images/wall.jpg");
    smileyTexture.init("images/awesomeface.png");
    shaderProgram.init("shaders/vshader.glsl", "shaders/fshader.glsl");

    triangle.init(&triangleMesh, &brickTexture, &shaderProgram);
    rectangle.init(&rectangleMesh, &brickTexture, &shaderProgram);

    shaderProgram.use();
    shaderProgram.setInt("texture1", 0);
    shaderProgram.setInt("texture2", 1);

    return true;
}

void OpenGLGraphics::shutdown() {
    glfwTerminate();
}

void OpenGLGraphics::update() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shaderProgram.use();
    brickTexture.use(GL_TEXTURE0);
    smileyTexture.use(GL_TEXTURE1);

    rectangleMesh.draw();

    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool OpenGLGraphics::isRunning() {
    return !glfwWindowShouldClose(window);
}
