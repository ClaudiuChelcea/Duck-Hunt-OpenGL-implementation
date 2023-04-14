#include "lab_m1/lab4/lab4.h"

#include <vector>
#include <string>
#include <iostream>

#include "lab_m1/lab4/transform3D.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */

float rotation = 0.0f;

glm::vec3 cube1_pos = { -2.5f, 0.5f, -1.5f };
glm::vec3 cubeSun_pos = { -5.0f, 5.0f, -5.0f };
float SunRotation = 1;
float EarhRotation = 1;
glm::vec3 cubeEarth_pos = { -5.0f, 8.0f, -5.0f };
float cube1_speed = 0.5f;
glm::vec3 cube2_scale = { 1.0f, 1.0, 1.0f };
glm::vec3 cube3_rotate{ 0.0f, 0.0f, 0.0f };
float posLeft = 0, posUp = 0, height = 192, width = 120;
float increaseDistance = 5.0f;
float slowTime = 0.1f;

Lab4::Lab4()
{
}


Lab4::~Lab4()
{
}


void Lab4::Init()
{
    polygonMode = GL_FILL;

    Mesh* mesh = new Mesh("box");
    mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
    meshes[mesh->GetMeshID()] = mesh;

    // Initialize tx, ty and tz (the translation steps)
    translateX = 0;
    translateY = 0;
    translateZ = 0;

    // Initialize sx, sy and sz (the scale factors)
    scaleX = 1;
    scaleY = 1;
    scaleZ = 1;

    // Initialize angular steps
    angularStepOX = 0;
    angularStepOY = 0;
    angularStepOZ = 0;
}


void Lab4::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Sets the screen area where to draw
    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);
}


void Lab4::Update(float deltaTimeSeconds)
{
    glLineWidth(3);
    glPointSize(5);
    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(cube1_pos.x, cube1_pos.y, cube1_pos.z);
    modelMatrix *= transform3D::Translate(translateX, translateY, translateZ);
    RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(0.0f, 0.5f, -1.5f);
    modelMatrix *= transform3D::Scale(scaleX, scaleY, scaleZ) * transform3D::Scale(cube2_scale.x, cube2_scale.y, cube2_scale.z);
    RenderMesh(meshes["box"], shaders["Simple"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(2.5f, 0.5f, -1.5f);
    modelMatrix *= transform3D::RotateOX(angularStepOX) * transform3D::RotateOX(cube3_rotate.x);
    modelMatrix *= transform3D::RotateOY(angularStepOY) * transform3D::RotateOY(cube3_rotate.y);;
    modelMatrix *= transform3D::RotateOZ(angularStepOZ) * transform3D::RotateOZ(cube3_rotate.z);;
    RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(cubeSun_pos.x, cubeSun_pos.y, cubeSun_pos.z);
    modelMatrix *= transform3D::Translate(translateX, translateY, translateZ);
    //modelMatrix *= transform3D::RotateOX(angularStepOX) * transform3D::RotateOX(SunRotation++ * slowTime);
    //modelMatrix *= transform3D::RotateOX(angularStepOY) * transform3D::RotateOY(SunRotation * slowTime);
    RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix * transform3D::RotateOY(rotation));
    rotation += 3 * deltaTimeSeconds;
    modelMatrix *= transform3D::RotateOZ(rotation);
    modelMatrix *= transform3D::Translate(1.0f, 1.0f, 1.0f);
    RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

    modelMatrix *= transform3D::RotateOZ(rotation);
    modelMatrix *= transform3D::Translate(1.0f, 1.0f, 1.0f);
    RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

    DrawCoordinateSystem();
    glClear(GL_DEPTH_BUFFER_BIT);
    glViewport(posLeft, posUp, height, width);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(cube1_pos.x, cube1_pos.y, cube1_pos.z);
    modelMatrix *= transform3D::Translate(translateX, translateY, translateZ);
    RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(0.0f, 0.5f, -1.5f);
    modelMatrix *= transform3D::Scale(scaleX, scaleY, scaleZ) * transform3D::Scale(cube2_scale.x, cube2_scale.y, cube2_scale.z);
    RenderMesh(meshes["box"], shaders["Simple"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(2.5f, 0.5f, -1.5f);
    modelMatrix *= transform3D::RotateOX(angularStepOX) * transform3D::RotateOX(cube3_rotate.x);
    modelMatrix *= transform3D::RotateOY(angularStepOY) * transform3D::RotateOY(cube3_rotate.y);;
    modelMatrix *= transform3D::RotateOZ(angularStepOZ) * transform3D::RotateOZ(cube3_rotate.z);;
    RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(cubeSun_pos.x, cubeSun_pos.y, cubeSun_pos.z);
    modelMatrix *= transform3D::Translate(translateX, translateY, translateZ);
    RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(cubeEarth_pos.x, cubeEarth_pos.y, cubeEarth_pos.z);
    modelMatrix *= transform3D::Translate(translateX, translateY, translateZ);
    RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

}


void Lab4::FrameEnd()
{
    DrawCoordinateSystem();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Lab4::OnInputUpdate(float deltaTime, int mods)
{
    // TODO(student): Add transformation logic]
    if (window->KeyHold(GLFW_KEY_W)) {
        cube1_pos.z -= cube1_speed * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_A)) {
        cube1_pos.x -= cube1_speed * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_S)) {
        cube1_pos.z += cube1_speed * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_D)) {
        cube1_pos.x += cube1_speed * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_R)) {
        cube1_pos.y += cube1_speed * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_F)) {
        cube1_pos.y -= cube1_speed * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_1)) {
        cube2_scale.x += 0.5 * deltaTime;
        cube2_scale.y += 0.5 * deltaTime;
        cube2_scale.z += 0.5 * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_2)) {
        cube2_scale.x -= 0.5 * deltaTime;
        cube2_scale.y -= 0.5 * deltaTime;
        cube2_scale.z -= 0.5 * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_3)) {
        cube3_rotate.x += 0.5 * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_4)) {
        cube3_rotate.x -= 0.5 * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_5)) {
        cube3_rotate.y += 0.5 * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_6)) {
        cube3_rotate.y -= 0.5 * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_7)) {
        cube3_rotate.z += 0.5 * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_8)) {
        cube3_rotate.z -= 0.5 * deltaTime;
    }
}


void Lab4::OnKeyPress(int key, int mods)
{
    // Add key press event
    if (key == GLFW_KEY_SPACE)
    {
        switch (polygonMode)
        {
        case GL_POINT:
            polygonMode = GL_FILL;
            break;
        case GL_LINE:
            polygonMode = GL_POINT;
            break;
        default:
            polygonMode = GL_LINE;
            break;
        }
    }

    if (key == GLFW_KEY_I) {
        if ((posLeft + increaseDistance) <= width) {
            posLeft += increaseDistance;
        }
    }

    if (key == GLFW_KEY_J) {
        if ((posLeft - increaseDistance) >= 0 ) {
            posLeft -= increaseDistance;
        }
    }

    if (key == GLFW_KEY_K) {
        if ((posUp + increaseDistance) <= height) {
            posUp += increaseDistance;
        }
    }

    if (key == GLFW_KEY_L) {
        if ((posUp - increaseDistance) >= 0) {
            posUp -= increaseDistance;
        }
    }

    if (key == GLFW_KEY_U) {
        height += increaseDistance;
        width += increaseDistance;
    }

    if (key == GLFW_KEY_O) {
        height -= increaseDistance;
        width -= increaseDistance;
    }
}


void Lab4::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Lab4::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Lab4::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Lab4::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Lab4::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Lab4::OnWindowResize(int width, int height)
{
}
