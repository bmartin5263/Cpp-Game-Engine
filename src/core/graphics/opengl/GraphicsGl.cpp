//
// Created by Brandon on 2/9/22.
//

#include "GraphicsGl.h"
#include <globals.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void makeTriangle(Polygon<MyVertex>* m) {
                                // POS              // TEXTURE
    m->vertices()[0] = MyVertex(-.5f, -.5f, 0.0f,   0.0f, 0.0f);  // bottom left
    m->vertices()[1] = MyVertex(0.5f, -.5f, 0.0f,   1.0f, 0.0f);  // bottom right
    m->vertices()[2] = MyVertex(0.0f, 0.5f, 0.0f,   0.5f, 1.0f);  // top

    m->triangles()[0][0] = 2;
    m->triangles()[0][1] = 0;
    m->triangles()[0][2] = 1;
}

void makeRectangle(Polygon<MyVertex>* m) {
                                // POS              // TEXTURE
    m->vertices()[0] = MyVertex(0.5f, 0.5f, 0.0f,   1.0f, 1.0f);  // top right
    m->vertices()[1] = MyVertex(0.5f, -.5f, 0.0f,   1.0f, 0.0f);  // bottom right
    m->vertices()[2] = MyVertex(-.5f, -.5f, 0.0f,   0.0f, 0.0f);  // bottom left
    m->vertices()[3] = MyVertex(-.5f, 0.5f, 0.0f,   0.0f, 1.0f);  // top left

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

bool GraphicsGl::startupImpl(int width, int height) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    this->width = (float) width;
    this->height = (float) height;

    window = glfwCreateWindow(width, height, "LearnOpenGL", nullptr, nullptr);
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
    glEnable(GL_DEPTH_TEST);

//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    trianglePolygon.init(3, 1);
    rectanglePolygon.init(4, 2);
    cubePolygon.init(36, 12);
    makeTriangle(&trianglePolygon);
    makeRectangle(&rectanglePolygon);
    makeCube(&cubePolygon);

    triangleMesh.init(&trianglePolygon);
    rectangleMesh.init(&rectanglePolygon);
    cubeMesh.init(&cubePolygon);

    brickTexture.init("images/wall.jpg");
    smileyTexture.init("images/awesomeface.png");
    shaderProgram.init("shaders/vshader.glsl", "shaders/fshader.glsl");

    shaderProgram.use();
    shaderProgram.setInt("texture1", 0);
    shaderProgram.setInt("texture2", 1);

    return true;
}

void GraphicsGl::shutdownImpl() {
    glfwTerminate();
}

void GraphicsGl::updateImpl() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram.use();
    brickTexture.use(GL_TEXTURE0);
    smileyTexture.use(GL_TEXTURE1);

    glm::mat4 transform = glm::mat4(1.0f);  // identity matrix
    transform = glm::translate(transform, glm::vec3(0.5f, -.5f, 0.0f));
    transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
    shaderProgram.setMatrix4("transform", transform);

    glm::mat4 view          = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 projection    = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.0f);
    view       = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//    // pass transformation matrices to the shader
    shaderProgram.setMatrix4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    shaderProgram.setMatrix4("view", view);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f,  0.0f,  0.0f));
    model = glm::rotate(model, glm::radians((float) glfwGetTime() * 12), glm::vec3(1.0f, 0.3f, 0.5f));
    shaderProgram.setMatrix4("model", model);

//    triangleMesh.draw();
    cubeMesh.draw();

    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool GraphicsGl::isRunningImpl() const {
    return !glfwWindowShouldClose(window);
}

void GraphicsGl::makeCube(Polygon<MyVertex> *m) {
//    m->vertices()[0] = MyVertex(-0.5f, -0.5f, -0.5f,  0.0f, 0.0f);
//    m->vertices()[1] = MyVertex(0.5f, -0.5f, -0.5f,  1.0f, 0.0f);
//    m->vertices()[2] = MyVertex(0.5f,  0.5f, -0.5f,  1.0f, 1.0f);

//    m->vertices()[3] = MyVertex(0.5f,  0.5f, -0.5f,  1.0f, 1.0f);
//    m->vertices()[4] = MyVertex(-0.5f,  0.5f, -0.5f,  0.0f, 1.0f);
//    m->vertices()[5] = MyVertex(-0.5f, -0.5f, -0.5f,  0.0f, 0.0f);

//    m->vertices()[6] = MyVertex(-0.5f, -0.5f,  0.5f,  0.0f, 0.0f);
//    m->vertices()[7] = MyVertex(0.5f, -0.5f,  0.5f,  1.0f, 0.0f);
//    m->vertices()[8] = MyVertex(0.5f,  0.5f,  0.5f,  1.0f, 1.0f);

//    m->vertices()[9] = MyVertex(0.5f,  0.5f,  0.5f,  1.0f, 1.0f);
//    m->vertices()[10] = MyVertex(-0.5f,  0.5f,  0.5f,  0.0f, 1.0f);
//    m->vertices()[11] = MyVertex(-0.5f, -0.5f,  0.5f,  0.0f, 0.0f);

//    m->vertices()[12] = MyVertex(-0.5f,  0.5f,  0.5f,  1.0f, 0.0f);
//    m->vertices()[13] = MyVertex(-0.5f,  0.5f, -0.5f,  1.0f, 1.0f);
//    m->vertices()[14] = MyVertex(-0.5f, -0.5f, -0.5f,  0.0f, 1.0f);
//    m->vertices()[15] = MyVertex(-0.5f, -0.5f, -0.5f,  0.0f, 1.0f);
//    m->vertices()[16] = MyVertex(-0.5f, -0.5f,  0.5f,  0.0f, 0.0f);
//    m->vertices()[17] = MyVertex(-0.5f,  0.5f,  0.5f,  1.0f, 0.0f);
//    m->vertices()[18] = MyVertex(0.5f,  0.5f,  0.5f,  1.0f, 0.0f);
//    m->vertices()[19] = MyVertex(0.5f,  0.5f, -0.5f,  1.0f, 1.0f);
//    m->vertices()[20] = MyVertex(0.5f, -0.5f, -0.5f,  0.0f, 1.0f);
//    m->vertices()[21] = MyVertex(0.5f, -0.5f, -0.5f,  0.0f, 1.0f);
//    m->vertices()[22] = MyVertex(0.5f, -0.5f,  0.5f,  0.0f, 0.0f);
//    m->vertices()[23] = MyVertex(0.5f,  0.5f,  0.5f,  1.0f, 0.0f);
//    m->vertices()[24] = MyVertex(-0.5f, -0.5f, -0.5f,  0.0f, 1.0f);
//    m->vertices()[25] = MyVertex(0.5f, -0.5f, -0.5f,  1.0f, 1.0f);
//    m->vertices()[26] = MyVertex(0.5f, -0.5f,  0.5f,  1.0f, 0.0f);
//    m->vertices()[27] = MyVertex(0.5f, -0.5f,  0.5f,  1.0f, 0.0f);
//    m->vertices()[28] = MyVertex(-0.5f, -0.5f,  0.5f,  0.0f, 0.0f);
//    m->vertices()[29] = MyVertex(-0.5f, -0.5f, -0.5f,  0.0f, 1.0f);
//    m->vertices()[30] = MyVertex(-0.5f,  0.5f, -0.5f,  0.0f, 1.0f);
//    m->vertices()[31] = MyVertex(0.5f,  0.5f, -0.5f,  1.0f, 1.0f);
//    m->vertices()[32] = MyVertex(0.5f,  0.5f,  0.5f,  1.0f, 0.0f);
//    m->vertices()[33] = MyVertex(0.5f,  0.5f,  0.5f,  1.0f, 0.0f);
//    m->vertices()[34] = MyVertex(-0.5f,  0.5f,  0.5f,  0.0f, 0.0f);
//    m->vertices()[35] = MyVertex(-0.5f,  0.5f, -0.5f,  0.0f, 1.0f);

    m->vertices()[0] = MyVertex(-.5f, -.5f, 0.5f,  0.0f, 0.0f);
    m->vertices()[1] = MyVertex(0.5f, -.5f, 0.5f,  1.0f, 0.0f);
    m->vertices()[2] = MyVertex(0.5f, 0.5f, 0.5f,  1.0f, 1.0f);
    m->vertices()[3] = MyVertex(-.5f, 0.5f, 0.5f,  0.0f, 1.0f);

    m->vertices()[4] = MyVertex(-.5f, -.5f, -.5f,  0.0f, 0.0f);
    m->vertices()[5] = MyVertex(0.5f, -.5f, -.5f,  1.0f, 0.0f);
    m->vertices()[6] = MyVertex(0.5f, 0.5f, -.5f,  1.0f, 1.0f);
    m->vertices()[7] = MyVertex(-.5f, 0.5f, -.5f,  0.0f, 1.0f);

    m->triangles()[0] = Triangle(0, 1, 2);
    m->triangles()[1] = Triangle(2, 3, 0);
    m->triangles()[2] = Triangle(1, 5, 6);
    m->triangles()[3] = Triangle(6, 2, 1);
    m->triangles()[4] = Triangle(7, 6, 5);
    m->triangles()[5] = Triangle(5, 4, 7);
    m->triangles()[6] = Triangle(4, 0, 3);
    m->triangles()[7] = Triangle(3, 7, 4);
    m->triangles()[8] = Triangle(4, 5, 1);
    m->triangles()[9] = Triangle(1, 0, 4);
    m->triangles()[10] = Triangle(3, 2, 6);
    m->triangles()[11] = Triangle(6, 7, 3);
}
