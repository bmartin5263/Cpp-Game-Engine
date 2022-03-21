//
// Created by Brandon on 1/30/22.
//

#include <iostream>
#include "SampleScene.h"
#include "io/Keyboard.h"
#include "ui/UI.h"

static void makeTriangle(Mesh& m) {
    auto vertices = new MyVertex[3];
    vertices[0] = MyVertex(-.5f, -.5f, 0.0f,   0.0f, 0.0f);  // bottom left
    vertices[1] = MyVertex(0.5f, -.5f, 0.0f,   1.0f, 0.0f);  // bottom right
    vertices[2] = MyVertex(0.0f, 0.5f, 0.0f,   0.5f, 1.0f);  // top

    auto triangles = new Triangle[1];
    triangles[0][0] = 2;
    triangles[0][1] = 0;
    triangles[0][2] = 1;

    m.init(vertices, 3, triangles, 1);
}
static void makeRectangle(Mesh& m) {
    // POS              // TEXTURE
    auto vertices = new MyVertex[4];
    vertices[0] = MyVertex(0.5f, 0.5f, 0.0f,   1.0f, 1.0f);  // top right
    vertices[1] = MyVertex(0.5f, -.5f, 0.0f,   1.0f, 0.0f);  // bottom right
    vertices[2] = MyVertex(-.5f, -.5f, 0.0f,   0.0f, 0.0f);  // bottom left
    vertices[3] = MyVertex(-.5f, 0.5f, 0.0f,   0.0f, 1.0f);  // top left

    auto triangles = new Triangle[2];
    triangles[0][0] = 0;
    triangles[0][1] = 1;
    triangles[0][2] = 3;
    triangles[1][0] = 1;
    triangles[1][1] = 2;
    triangles[1][2] = 3;

    m.init(vertices, 4, triangles, 2);
}
static void makeCube(Mesh& m) {
    auto vertices = new MyVertex[8];
    vertices[0] = MyVertex(-.5f, -.5f, 0.5f,  0.0f, 0.0f);
    vertices[1] = MyVertex(0.5f, -.5f, 0.5f,  1.0f, 0.0f);
    vertices[2] = MyVertex(0.5f, 0.5f, 0.5f,  1.0f, 1.0f);
    vertices[3] = MyVertex(-.5f, 0.5f, 0.5f,  0.0f, 1.0f);

    vertices[4] = MyVertex(-.5f, -.5f, -.5f,  0.0f, 0.0f);
    vertices[5] = MyVertex(0.5f, -.5f, -.5f,  1.0f, 0.0f);
    vertices[6] = MyVertex(0.5f, 0.5f, -.5f,  1.0f, 1.0f);
    vertices[7] = MyVertex(-.5f, 0.5f, -.5f,  0.0f, 1.0f);

    auto triangles = new Triangle[12];
    triangles[0] = Triangle(0, 1, 2);
    triangles[1] = Triangle(2, 3, 0);
    triangles[2] = Triangle(1, 5, 6);
    triangles[3] = Triangle(6, 2, 1);
    triangles[4] = Triangle(7, 6, 5);
    triangles[5] = Triangle(5, 4, 7);
    triangles[6] = Triangle(4, 0, 3);
    triangles[7] = Triangle(3, 7, 4);
    triangles[8] = Triangle(4, 5, 1);
    triangles[9] = Triangle(1, 0, 4);
    triangles[10] = Triangle(3, 2, 6);
    triangles[11] = Triangle(6, 7, 3);

    m.init(vertices, 8, triangles, 12);
}

SampleScene::SampleScene() {
    std::cout << "new SampleScene()\n";
}

void SampleScene::initialize() {
    makeTriangle(triangleMesh);
    makeRectangle(rectangleMesh);
    makeCube(cubeMesh);

//    brickTexture.init("images/wall.jpg");
//    smileyTexture.init("images/awesomeface.png");

    shaderProgram.use();
    shaderProgram.setInt("texture1", 0);
    shaderProgram.setInt("texture2", 1);
}

void SampleScene::destroy() {
    std::cout << "SampleScene::destroy()\n";
}

SampleScene::~SampleScene() {
    std::cout << "~SampleScene()\n";
}

void SampleScene::update() {
    auto deltaTime = Engine::deltaTime();
    if (Keyboard::isKeyPressed(Key::W)) {
        camera.processKeyboard(FORWARD, deltaTime);
    }
    if (Keyboard::isKeyPressed(Key::S)) {
        camera.processKeyboard(BACKWARD, deltaTime);
    }
    if (Keyboard::isKeyPressed(Key::A)) {
        camera.processKeyboard(LEFT, deltaTime);
    }
    if (Keyboard::isKeyPressed(Key::D)) {
        camera.processKeyboard(RIGHT, deltaTime);
    }

    shaderProgram.use();
    brickTexture.use(GL_TEXTURE0);
    smileyTexture.use(GL_TEXTURE1);

    glm::mat4 projection = glm::ortho(0.0f, (float) UI::width(), (float) UI::height(), 0.0f, -1.0f, 1.0f);
    shaderProgram.setMatrix4("projection", projection);

    // camera/view transformation
    glm::mat4 view = camera.getViewMatrix();
    shaderProgram.setMatrix4("view", view);

    glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 0.3f, 0.5f));

    shaderProgram.setMatrix4("model", model);
    shaderProgram.setMatrix4("view", view);
    shaderProgram.setMatrix4("projection", projection);

    cubeMesh.draw(shaderProgram);
}