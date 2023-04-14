#include "lab_m1/lab1/lab1.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace m1;

// Objects from the 'models' folder
namespace Objects
{
    std::string QUAD_OBJ = "quad.obj";
    std::string SPHERE_OBJ = "sphere.obj";
    std::string BOX_OBJ = "box.obj";
    std::string TEAPOT_OBJ = "teapot.obj";
    std::string PLANE50_OBJ = "plane50.obj";
    std::string SCREEN_QUAD_OBJ = "screen_quad.obj";
    std::string QUAD_STRING = "quad";
    std::string SPHERE_STRING = "sphere";
    std::string BOX_STRING = "box";
    std::string TEAPOT_STRING = "teapot";
    std::string PLANE50_STRING = "plane50";
    std::string SCREEN_QUAD_STRING = "screen_quad";
};

#define GRAVITY_PULL 0.75f

class Vector3
{
    public:
        float x{ 0 }, y{ 0 }, z{ 0 };
        Vector3() = default;

        Vector3(float x, float y, float z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }
};

class RGBA : public Vector3
{
    public:
        float opacity{ 1 };
        RGBA() {
            this->x = 0;
            this->y = 0;
            this->z = 0;
            this->opacity = 1;
        }

        RGBA(float x, float y, float z, float opacity = 1) : Vector3 (x, y, z) {
            this->opacity = opacity;
        }

        void debugME() {
            std::cout << this->x << " " << this->y << " " << this->z << " " << this->opacity << std::endl;
        }
};

class Player
{
    public:
        Vector3 position;
        std::string activeMesh = Objects::SPHERE_STRING;
        bool movingForward = false, movingBackward = false, movingRight = false, movingLeft = false, movingUp = false, movingDown = false;
        float movingZ_speed = 0.5f, movingX_speed = 0.5f, movingY_speed = 0.5f;
        bool jump = false;
        float jumpForce = 0.01f;
        float heightLimitUp = 1.0f, heightLimitDown = 0.0f, goUpFrom = 0.0f, goDownFrom = 1.0f;
        bool haveToGoDown = false;
        bool ascending = false;
} player_1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */

RGBA RED = { 255.0f, 0.0f, 0.0f, 1.0f };
RGBA GREEN = { 0.0f, 255.0f, 0.0f, 1.0f };
RGBA BLUE = { 0.0f, 0.0f, 255.0f, 1.0f };
RGBA BLACK = { 0.0f, 0.0f, 0.0f, 1.0f };

enum Colors {
    RED_COLOR,
    GREEN_COLOR,
    BLUE_COLOR,
    BLACK_COLOR
} activeColor; // RED COLOR



Lab1::Lab1()
{
    activeColor = RED_COLOR;
}


Lab1::~Lab1()
{
}


void Lab1::Init()
{
    // Load a mesh from file into GPU memory. We only need to do it once,
    // no matter how many times we want to draw this mesh.
    {
        Mesh* mesh = new Mesh(Objects::BOX_STRING);
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), Objects::BOX_OBJ);
        meshes[mesh->GetMeshID()] = mesh;
    }

    // Load a mesh from file into GPU memory. We only need to do it once,
    // no matter how many times we want to draw this mesh.
    {
        Mesh* mesh_2 = new Mesh(Objects::QUAD_STRING);
        mesh_2->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), Objects::QUAD_OBJ);
        meshes[mesh_2->GetMeshID()] = mesh_2;
    }

    // Load a mesh from file into GPU memory. We only need to do it once,
    // no matter how many times we want to draw this mesh.
    {
        Mesh* mesh_3 = new Mesh(Objects::SPHERE_STRING);
        mesh_3->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), Objects::SPHERE_OBJ);
        meshes[mesh_3->GetMeshID()] = mesh_3;
    }

    // Load a mesh from file into GPU memory. We only need to do it once,
    // no matter how many times we want to draw this mesh.
    {
        Mesh* mesh_4 = new Mesh(Objects::SCREEN_QUAD_STRING);
        mesh_4->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), Objects::SCREEN_QUAD_OBJ);
        meshes[mesh_4->GetMeshID()] = mesh_4;
    }

    // Load a mesh from file into GPU memory. We only need to do it once,
    // no matter how many times we want to draw this mesh.
    {
        Mesh* mesh_5 = new Mesh(Objects::PLANE50_STRING);
        mesh_5->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), Objects::PLANE50_OBJ);
        meshes[mesh_5->GetMeshID()] = mesh_5;
    }

    // Load a mesh from file into GPU memory. We only need to do it once,
    // no matter how many times we want to draw this mesh.
    {
        Mesh* mesh_6 = new Mesh(Objects::TEAPOT_STRING);
        mesh_6->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), Objects::TEAPOT_OBJ);
        meshes[mesh_6->GetMeshID()] = mesh_6;
    }
}


void Lab1::FrameStart()
{
}


void Lab1::Update(float deltaTimeSeconds)
{
    glm::ivec2 resolution = window->props.resolution;

    // Sets the clear color for the color buffer
    switch (activeColor) {
    case RED_COLOR:
        glClearColor(GREEN.x, GREEN.y, GREEN.z, GREEN.z);
        break;
    case GREEN_COLOR:
        glClearColor(BLUE.x, BLUE.y, BLUE.z, BLUE.z);
        break;
    case BLUE_COLOR:
        glClearColor(RED.x, RED.y, RED.z, RED.z);
        break;
    default:
        glClearColor(BLACK.x, BLACK.y, BLACK.z, BLACK.z);
        break;
    }
    
    // Clears the color buffer (using the previously set color) and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);

    // Render the object
    RenderMesh(meshes["box"], glm::vec3(2, 0.5f, 0), glm::vec3(0.5f));

    // Render the object again but with different properties
    RenderMesh(meshes["box"], glm::vec3(-2, 0.5f, 0));

    // Render the object again but with different properties
    RenderMesh(meshes[player_1.activeMesh], glm::vec3(player_1.position.x, player_1.position.y, player_1.position.z));

    // Jump mechanic for player
    if (player_1.jump == true) {
        if (player_1.goUpFrom <= player_1.heightLimitUp) {
            player_1.goUpFrom += deltaTimeSeconds;
            player_1.position.y = player_1.position.y + player_1.goUpFrom * player_1.jumpForce;
            if ((player_1.jumpForce - deltaTimeSeconds / 10) > 0.01f)
               player_1.jumpForce = player_1.jumpForce - deltaTimeSeconds / 10;
            player_1.ascending = true;
        }
        else {
            player_1.goUpFrom = 0;
            player_1.jump = false;
            player_1.ascending = false;
        }
    }

    // GRAVITY
    if (player_1.position.y > 0.0f && player_1.ascending == false) {
        player_1.position.y -= GRAVITY_PULL * deltaTimeSeconds;
    }
}


void Lab1::FrameEnd()
{
    DrawCoordinateSystem();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


 // Treat continuous update based on input
void Lab1::OnInputUpdate(float deltaTime, int mods)
{
    if (player_1.movingForward == true) {
        player_1.position.z -= player_1.movingZ_speed * deltaTime;
    }
    if (player_1.movingBackward == true) {
        player_1.position.z += player_1.movingZ_speed * deltaTime;
    }
    if (player_1.movingLeft == true) {
        player_1.position.x -= player_1.movingX_speed * deltaTime;
    }
    if (player_1.movingRight == true) {
        player_1.position.x += player_1.movingX_speed * deltaTime;
    }
    if (player_1.movingUp == true) {
        player_1.position.y += player_1.movingY_speed * deltaTime;
    }
    if (player_1.movingDown == true) {
        player_1.position.y -= player_1.movingY_speed * deltaTime;
    }
}


void Lab1::OnKeyPress(int key, int mods)
{
    // Add key press event
    if (key == GLFW_KEY_F) {
        switch (activeColor) {
            case RED_COLOR:
                activeColor = GREEN_COLOR;
                break;
            case GREEN_COLOR:
                activeColor = BLUE_COLOR;
                break;
            case BLUE_COLOR:
                activeColor = RED_COLOR;
                break;
            default:
                activeColor = BLACK_COLOR;
                break;
        }
    }

    // Add key press event
    if (key == GLFW_KEY_G) {
        // Sphere -> Quad
        if (strcmp(player_1.activeMesh.c_str(), Objects::SPHERE_STRING.c_str()) == 0) {
            player_1.activeMesh = Objects::QUAD_STRING;
        }
        // Quad -> Box
        else if (strcmp(player_1.activeMesh.c_str(), Objects::QUAD_STRING.c_str()) == 0) {
            player_1.activeMesh = Objects::BOX_STRING;
        }
        // Box -> Plane50
        else if (strcmp(player_1.activeMesh.c_str(), Objects::BOX_STRING.c_str()) == 0) {
            player_1.activeMesh = Objects::PLANE50_STRING;
        }
        // Plane50 -> Screen_Quad
        else if (strcmp(player_1.activeMesh.c_str(), Objects::PLANE50_STRING.c_str()) == 0) {
            player_1.activeMesh = Objects::SCREEN_QUAD_STRING;
        }
        // Screen_Quad -> Teapot
        else if (strcmp(player_1.activeMesh.c_str(), Objects::SCREEN_QUAD_STRING.c_str()) == 0) {
            player_1.activeMesh = Objects::TEAPOT_STRING;
        }
        // Teapot -> Sphere
        else if (strcmp(player_1.activeMesh.c_str(), Objects::TEAPOT_STRING.c_str()) == 0) {
            player_1.activeMesh = Objects::SPHERE_STRING;
        }
    }

    // Add key press event
    if (key == GLFW_KEY_W) {
        player_1.movingForward = true;
    }
    if (key == GLFW_KEY_S) {
        player_1.movingBackward = true;
    }
    if (key == GLFW_KEY_A) {
        player_1.movingLeft = true;
    }
    if (key == GLFW_KEY_D) {
        player_1.movingRight = true;
    }
    if (key == GLFW_KEY_Q) {
        player_1.movingUp = true;
    }
    if (key == GLFW_KEY_E) {
        player_1.movingDown = true;
    }

    // Jump
    // Add key press event
    if (key == GLFW_KEY_SPACE) {
        player_1.jump = true;
        player_1.jumpForce = 0.08f;
    }
}


void Lab1::OnKeyRelease(int key, int mods)
{
    // Add key release event
    if (key == GLFW_KEY_W) {
        player_1.movingForward = false;
    }
    if (key == GLFW_KEY_S) {
        player_1.movingBackward = false;
    }
    if (key == GLFW_KEY_A) {
        player_1.movingLeft = false;
    }
    if (key == GLFW_KEY_D) {
        player_1.movingRight = false;
    }
    if (key == GLFW_KEY_Q) {
        player_1.movingUp = false;
    }
    if (key == GLFW_KEY_E) {
        player_1.movingDown = false;
    }
}

void Lab1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Lab1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Lab1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Lab1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
    // Treat mouse scroll event
}


void Lab1::OnWindowResize(int width, int height)
{
    // Treat window resize event
}
