#include "Tema2.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace m1;

/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */

Tema2::Tema2() {}
Tema2::~Tema2() {}

void Tema2::Init()
{
    srand(time(NULL));

    // Set camera
    camera->Set(glm::vec3(0, 2, 3.5f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));

    // Get resolution
    glm::ivec2 resolution = window->GetResolution();
    miniViewport = Viewport(50, 50, resolution.x / 5.f, resolution.y / 5.f);
    projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);

    // Points for path
    {
        MainPoints[0] = glm::vec3(0, 0, 0);
        MainPoints[1] = glm::vec3(-0.41, 0, 1.95);
        MainPoints[2] = glm::vec3(-1.18, 0, 3.77);
        MainPoints[3] = glm::vec3(-1.74, 0, 6.22);
        MainPoints[4] = glm::vec3(-2.3, 0, 7.9);
        MainPoints[5] = glm::vec3(-3.28, 0, 9.79);
        MainPoints[6] = glm::vec3(-3.98, 0, 11.75);
        MainPoints[7] = glm::vec3(-4.41, 0, 13.79);
        MainPoints[8] = glm::vec3(-4.27, 0, 15.96);
        MainPoints[9] = glm::vec3(-3.98, 0, 17.92);
        MainPoints[10] = glm::vec3(-3.56, 0, 20.51);
        MainPoints[11] = glm::vec3(-3.91, 0, 23.03);
        MainPoints[12] = glm::vec3(-5, 0, 25);
        MainPoints[13] = glm::vec3(-6.23, 0, 26.39);
        MainPoints[14] = glm::vec3(-7.77, 0, 27.23);
        MainPoints[15] = glm::vec3(-9.24, 0, 27.51);
        MainPoints[16] = glm::vec3(-11.2, 0, 27.16);
        MainPoints[17] = glm::vec3(-12.04, 0, 26.04);
        MainPoints[18] = glm::vec3(-13.16, 0, 24.99);
        MainPoints[19] = glm::vec3(-15, 0, 25);
        MainPoints[20] = glm::vec3(-16.66, 0, 26.32);
        MainPoints[21] = glm::vec3(-17.36, 0, 28.01);
        MainPoints[22] = glm::vec3(-17.5, 0, 30.32);
        MainPoints[23] = glm::vec3(-17.08, 0, 32.28);
        MainPoints[24] = glm::vec3(-16.38, 0, 34.52);
        MainPoints[25] = glm::vec3(-15.78, 0, 38.01);
        MainPoints[26] = glm::vec3(-15.89, 0, 40.98);
        MainPoints[27] = glm::vec3(-17.87, 0, 42.52);
        MainPoints[28] = glm::vec3(-20.4, 0, 43.4);
        MainPoints[29] = glm::vec3(-23.15, 0, 43.18);
        MainPoints[30] = glm::vec3(-25.57, 0, 42.19);
        MainPoints[31] = glm::vec3(-27.33, 0, 40.65);
        MainPoints[32] = glm::vec3(-29.2, 0, 38.23);
        MainPoints[33] = glm::vec3(-30.3, 0, 35.58);
        MainPoints[34] = glm::vec3(-30.85, 0, 33.93);
        MainPoints[35] = glm::vec3(-31.84, 0, 31.62);
        MainPoints[36] = glm::vec3(-34.71, 0, 30.63);
        MainPoints[37] = glm::vec3(-36.91, 0, 31.95);
        MainPoints[38] = glm::vec3(-38.67, 0, 33.82);
        MainPoints[39] = glm::vec3(-41.09, 0, 35.58);
        MainPoints[40] = glm::vec3(-43.51, 0, 36.57);
        MainPoints[41] = glm::vec3(-46.59, 0, 36.46);
        MainPoints[42] = glm::vec3(-48.13, 0, 34.7);
        MainPoints[43] = glm::vec3(-48.35, 0, 32.83);
        MainPoints[44] = glm::vec3(-47.47, 0, 30.08);
        MainPoints[45] = glm::vec3(-45.6, 0, 28.43);
        MainPoints[46] = glm::vec3(-43.95, 0, 26.67);
        MainPoints[47] = glm::vec3(-42.19, 0, 25.46);
        MainPoints[48] = glm::vec3(-39.99, 0, 24.47);
        MainPoints[49] = glm::vec3(-37.35, 0, 23.7);
        MainPoints[50] = glm::vec3(-34.27, 0, 22.93);
        MainPoints[51] = glm::vec3(-31.09, 0, 23.14);
        MainPoints[52] = glm::vec3(-28.54, 0, 21.61);
        MainPoints[53] = glm::vec3(-27.55, 0, 19.74);
        MainPoints[54] = glm::vec3(-27.55, 0, 17.97);
        MainPoints[55] = glm::vec3(-27.66, 0, 15.77);
        MainPoints[56] = glm::vec3(-27.99, 0, 14.01);
        MainPoints[57] = glm::vec3(-28.54, 0, 12.03);
        MainPoints[58] = glm::vec3(-27.11, 0, 10.05);
        MainPoints[59] = glm::vec3(-24.8, 0, 8.51);
        MainPoints[60] = glm::vec3(-22.6, 0, 7.63);
        MainPoints[61] = glm::vec3(-20.62, 0, 6.86);
        MainPoints[62] = glm::vec3(-18.31, 0, 6.42);
        MainPoints[63] = glm::vec3(-15.89, 0, 5.65);
        MainPoints[64] = glm::vec3(-13.35, 0, 4.88);
        MainPoints[65] = glm::vec3(-11.04, 0, 4.11);
        MainPoints[66] = glm::vec3(-9.06, 0, 3.23);
        MainPoints[67] = glm::vec3(-7.52, 0, 1.25);
        MainPoints[68] = glm::vec3(-5.65, 0, 0.37);
        MainPoints[69] = glm::vec3(-3.89, 0, -0.51);
        MainPoints[70] = glm::vec3(-1.13, 0, -1.71);
    }
    
    // Player's car
    {
        vector<VertexFormat> verticesCar
        {
            VertexFormat(myRectangle.getCorners()[0], myPlayer.getPlayerColor()),
            VertexFormat(myRectangle.getCorners()[1], myPlayer.getPlayerColor()),
            VertexFormat(myRectangle.getCorners()[2], myPlayer.getPlayerColor()),
            VertexFormat(myRectangle.getCorners()[3], myPlayer.getPlayerColor()),
            VertexFormat(myRectangle.getCorners()[4], myPlayer.getPlayerColor()),
            VertexFormat(myRectangle.getCorners()[5], myPlayer.getPlayerColor()),
            VertexFormat(myRectangle.getCorners()[6], myPlayer.getPlayerColor()),
            VertexFormat(myRectangle.getCorners()[7], myPlayer.getPlayerColor()),
        };

        vector<unsigned int> indicesCar = myPlayer.getDefaultIndicesCar();
        meshes[myPlayer.getObjectName()] = new Mesh("Player");
        meshes[myPlayer.getObjectName()]->InitFromData(verticesCar, indicesCar);
    }

    // Enemy 1
    {
        vector<VertexFormat> verticesCar
        {
            VertexFormat(myRectangle.getCorners()[0], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[1], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[2], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[3], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[4], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[5], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[6], enemy_1.getColor()),
            VertexFormat(myRectangle.getCorners()[7], enemy_1.getColor()),

        };

        vector<unsigned int> indicesCar = enemy_1.getDefaultIndicesCar();
        meshes[enemy_1.getObjectName()] = new Mesh("First");
        meshes[enemy_1.getObjectName()]->InitFromData(verticesCar, indicesCar);
    }

    // Enemy 2
    {
        vector<VertexFormat> verticesCar
        {
            VertexFormat(myRectangle.getCorners()[0], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[1], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[2], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[3], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[4], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[5], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[6], enemy_2.getColor()),
            VertexFormat(myRectangle.getCorners()[7], enemy_2.getColor()),

        };

        vector<unsigned int> indicesCar = enemy_2.getDefaultIndicesCar();
        meshes[enemy_2.getObjectName()] = new Mesh("Second");
        meshes[enemy_2.getObjectName()]->InitFromData(verticesCar, indicesCar);
    }

    // Enemy 3
    {
        vector<VertexFormat> verticesCar
        {
            VertexFormat(myRectangle.getCorners()[0], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[1], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[2], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[3], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[4], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[5], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[6], enemy_3.getColor()),
            VertexFormat(myRectangle.getCorners()[7], enemy_3.getColor()),
        };

        vector<unsigned int> indicesCar = enemy_3.getDefaultIndicesCar();
        meshes[enemy_3.getObjectName()] = new Mesh("Third");
        meshes[enemy_3.getObjectName()]->InitFromData(verticesCar, indicesCar);
    }
   
    // Ground
    {
        vector<VertexFormat> verticesGround
        {
            VertexFormat(glm::vec3(0, 0, 500), glm::vec3(0.3f, 0.5f, 0.3f)),
            VertexFormat(glm::vec3(500, 0, 500), glm::vec3(0.3f, 0.5f, 0.3)),
            VertexFormat(glm::vec3(0, 0, 500), glm::vec3(0.3f, 0.5f, 0.3)),
            VertexFormat(glm::vec3(500, 0, 500), glm::vec3(0.3f, 0.5f, 0.3)),
            VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0.3f, 0.5f, 0.3)),
            VertexFormat(glm::vec3(500, 0, 0), glm::vec3(0.3f, 0.5f, 0.3)),
            VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0.3f, 0.5f, 0.3)),
            VertexFormat(glm::vec3(500, 0, 0), glm::vec3(0.3f, 0.5f, 0.3)),

        };

        vector<unsigned int> indicesGround =
        {
            0, 1, 2,
            1, 3, 2,
            2, 3, 7,
            2, 7, 6,
            1, 7, 3,
            1, 5, 7,
            6, 7, 4,
            7, 5, 4,
            0, 4, 1,
            1, 4, 5,
            2, 6, 4,
            0, 2, 4
        };

        meshes["ground"] = new Mesh("Ground");
        meshes["ground"]->InitFromData(verticesGround, indicesGround);
    }

    // Tree tops
    {
        vector<VertexFormat> vertices{
            VertexFormat(glm::vec3(0, 0, 1.5), glm::vec3(0.0f, 0.4f, 0.9f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(1.5, 0, 1.5), glm::vec3(0.0f, 0.4f, 0.9f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(0, 1.5, 1.5), glm::vec3(0.0f, 0.4f, 0.9f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(1.5, 1.5, 1.5), glm::vec3(0.0f, 0.4f, 0.9f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0.0f, 0.4f, 0.9f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(1.5, 0, 0), glm::vec3(0.0f, 0.4f, 0.9f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(0, 1.5, 0), glm::vec3(0.0f, 0.4f, 0.9f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(1.5, 1.5, 0), glm::vec3(0.0f, 0.4f, 0.9f), UP, glm::vec2(1)),
        };

        vector<unsigned int> indices = {
            0, 1, 2,
            2, 3, 7,
            2, 7, 6,
            1, 7, 3,
            1, 5, 7,
            6, 7, 4,
            7, 5, 4,
            0, 4, 1,
            1, 4, 5,
            2, 6, 4,
            0, 2, 4, };
        meshes["treeTop"] = new Mesh("Tree top");
        meshes["treeTop"]->InitFromData(vertices, indices);
    }

    // Tree trunks
    {
        vector<VertexFormat> vertices{
            VertexFormat(glm::vec3(0, 0, 0.5), glm::vec3(0.0f, 0.7f, 0.7f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(0.5, 0, 0.5), glm::vec3(0.0f, 0.7f, 0.7f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(0, 1.5, 0.5), glm::vec3(0.0f, 0.7f, 0.7f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(0.5, 1.5, 0.5), glm::vec3(0.0f, 0.7f, 0.7f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0.0f, 0.7f, 0.7f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(0.5, 0, 0), glm::vec3(0.0f, 0.7f, 0.7f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(0, 1.5, 0), glm::vec3(0.0f, 0.7f, 0.7f), UP, glm::vec2(1)),
            VertexFormat(glm::vec3(0.5, 1.5, 0), glm::vec3(0.0f, 0.7f, 0.7f), UP, glm::vec2(1)),
        };

        std::vector<unsigned int> indices = {
            0, 1, 2,
            1, 3, 2,
            2, 3, 7,
            2, 7, 6,
            1, 7, 3,
            1, 5, 7,
            6, 7, 4,
            7, 5, 4,
            0, 4, 1,
            1, 4, 5,
            2, 6, 4,
            0, 2, 4, };
        meshes["trunk"] = new Mesh("Trunk");
        meshes["trunk"]->InitFromData(vertices, indices);
    }

    /* Calculate path */
    // For all points but 0
    for (int i = 0; i < 70; i++) {
        glm::vec3 PATH = cross(MainPoints[i + 1] - MainPoints[i], UP);
        RedPoints[i] = MainPoints[i] + DistanceToRedPath * PATH;
        BluePoints[i] = MainPoints[i] - DistanceToBluePath * PATH;
        RedPath[i] = MainPoints[i] + DistToRed * PATH;
        BluePath[i] = MainPoints[i] - DistToBlue * PATH;
    }

    // For 0 point
    RedPoints[70] = MainPoints[70] + DistanceToRedPath * cross(MainPoints[0] - MainPoints[70], UP);
    BluePoints[70] = MainPoints[70] - DistanceToBluePath * cross(MainPoints[0] - MainPoints[70], UP);
  
    // Start indexes of cars
    enemy_1.setStartIndex(rand() % 70);
    enemy_2.setStartIndex(rand() % 70);
    enemy_3.setStartIndex(rand() % 70);
}

// Render the scene
void Tema2::RenderScene(implement::Camera* camera)
{
    // Ground
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(-300, 0, -160);
    RenderMesh(meshes["ground"], shaders["VertexColor"], modelMatrix, camera);

    // Path
    // Draw 70 - 0 point
    vector<VertexFormat> verticesPath{
          VertexFormat(glm::vec3(RedPoints[70].x, 0.1, RedPoints[70].z), glm::vec3(0.25f, 0.35f, 0.45f)),
          VertexFormat(glm::vec3(BluePoints[70].x, 0.1, BluePoints[70].z), glm::vec3(0.25f, 0.35f, 0.45f)),
          VertexFormat(glm::vec3(RedPoints[0].x, 0.1, RedPoints[0].z), glm::vec3(0.25f, 0.35f, 0.45f)),
          VertexFormat(glm::vec3(BluePoints[0].x, 0.1, BluePoints[0].z), glm::vec3(0.25f, 0.35f, 0.45f)),
    };

    vector<unsigned int> indicesPath = {
            0, 1, 3,
            0, 3, 2,
    };

    meshes["path"] = new Mesh("generated path");
    meshes["path"]->InitFromData(verticesPath, indicesPath);
    modelMatrix = glm::mat4(1);
    RenderMesh(meshes["path"], shaders["VertexColor"], modelMatrix, camera);

    // Draw all other points and trees
    for (int i = 0; i < 70; i++) {
        modelMatrix = glm::mat4(1);
        vector<VertexFormat> verticesPath{
          VertexFormat(glm::vec3(RedPoints[i].x, 0.1, RedPoints[i].z), glm::vec3(0.25f, 0.35f, 0.45f)),
          VertexFormat(glm::vec3(BluePoints[i].x, 0.1, BluePoints[i].z), glm::vec3(0.25f, 0.35f, 0.45f)),
          VertexFormat(glm::vec3(RedPoints[i + 1].x, 0.1, RedPoints[i + 1].z), glm::vec3(0.25f, 0.35f, 0.45f)),
          VertexFormat(glm::vec3(BluePoints[i + 1].x, 0.1, BluePoints[i + 1].z), glm::vec3(0.25f, 0.35f, 0.45f)),
        };

        vector<unsigned int> indicesPath = {
                0, 1, 3,
                0, 3, 2,
        };

        meshes["path"] = new Mesh("Path");
        meshes["path"]->InitFromData(verticesPath, indicesPath);
        RenderMesh(meshes["path"], shaders["VertexColor"], modelMatrix, camera);

        // Render the trees
        if (i >= 0 && i <= 31) {
            modelMatrix = glm::mat4(1);

            // Tree trunk
            modelMatrix *= transform3D::Translate(BluePoints[i].x + 3, 0, BluePoints[i].z + 8.1);
            RenderMesh(meshes["trunk"], shaders["VertexColor"], modelMatrix, camera);

            // Tree top
            modelMatrix *= transform3D::Translate(-0.5, 1.53, -0.5);
            RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrix, camera);

            if (i > 1 && i <= 29) {
                glm::mat4 modelMatrixCopy = glm::mat4(1);

                // Trunk
                modelMatrixCopy *= transform3D::Translate(RedPoints[i].x - 1.3, 0, RedPoints[i].z - 2);
                RenderMesh(meshes["trunk"], shaders["VertexColor"], modelMatrixCopy, camera);

                // Tree top
                modelMatrixCopy *= transform3D::Translate(-0.5, 1.53, -0.5);
                RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrixCopy, camera);
            }
        }
        else {
            if (i > 31 && i < 37) {
                glm::mat4 modelMatrixCopy = glm::mat4(1);

                // Tree trunk
                modelMatrixCopy *= transform3D::Translate(BluePoints[i].x - 2, 0, BluePoints[i].z + 3);
                RenderMesh(meshes["trunk"], shaders["VertexColor"], modelMatrixCopy, camera);

                // Tree top
                modelMatrixCopy *= transform3D::Translate(-0.5, 1.53, -0.5);
                RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrixCopy, camera);

                modelMatrixCopy = glm::mat4(1);

                // Tree trunk
                modelMatrixCopy *= transform3D::Translate(RedPoints[i].x + 4, 0, RedPoints[i].z);
                RenderMesh(meshes["trunk"], shaders["VertexColor"], modelMatrixCopy, camera);

                // Tree top
                modelMatrixCopy *= transform3D::Translate(-0.5, 1.53, -0.5);
                RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrixCopy, camera);
            }

            if (i > 38 && i < 41) {
                glm::mat4 modelMatrixCopy = glm::mat4(1);

                // Tree trunk
                modelMatrixCopy *= transform3D::Translate(BluePoints[i].x + 6, 0, BluePoints[i].z - 1);
                RenderMesh(meshes["trunk"], shaders["VertexColor"], modelMatrixCopy, camera);

                // Tree top
                modelMatrixCopy *= transform3D::Translate(-0.5, 1.53, -0.5);
                RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrixCopy, camera);
            }
            if (i > 41 && i < 69) {
                glm::mat4 modelMatrixCopy = glm::mat4(1);

                // Tree trunk
                modelMatrix *= transform3D::Translate(BluePoints[i].x - 2, 0, BluePoints[i].z - 3.5);
                RenderMesh(meshes["trunk"], shaders["VertexColor"], modelMatrix, camera);

                // Tree top
                modelMatrix *= transform3D::Translate(-0.5, 1.53, -0.5);
                RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrix, camera);

                modelMatrixCopy = glm::mat4(1);

                // Tree trunk
                modelMatrixCopy *= transform3D::Translate(RedPoints[i].x + 2.3, 0, RedPoints[i].z);
                RenderMesh(meshes["trunk"], shaders["VertexColor"], modelMatrixCopy, camera);

                // Tree top
                modelMatrixCopy *= transform3D::Translate(-0.5, 1.53, -0.5);
                RenderMesh(meshes["treeTop"], shaders["VertexColor"], modelMatrixCopy, camera);
            }
        }
    }
}

void Tema2::FrameStart()
{   
    // Set the color of the sky 
    float R = 255;
    float G = 192;
    float vec2 = 203;
    glClearColor((float)R/255, (float)G/255, (float)vec2/255, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Tema2::Update(float deltaTimeSeconds)
{
    glClear(GL_DEPTH_BUFFER_BIT);
    glm::ivec2 resolution = window->GetResolution();

    // --------------------------------------------------------- MAIN VIEWPORT ---------------------------------------------------------
    glViewport(0, 0, resolution.x, resolution.y);
    projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);

    /* Camera */
    RenderScene(camera);
    camera->Set(glm::vec3(0, 2, 3.5f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(myPlayer.getTranslation().x, myPlayer.getTranslation().y, myPlayer.getTranslation().z);
    camera->MoveForward(-myPlayer.getTranslation().z);
    camera->TranslateRight(myPlayer.getTranslation().x);

    // Move after player
    modelMatrix *= transform3D::Translate(0, 0.3, 0);
    modelMatrix *= transform3D::Translate(0.5, 0, 0);
    modelMatrix *= transform3D::RotateOY(myPlayer.getRotationAngle());
    modelMatrix *= transform3D::Translate(-0.5, 0, 0);

    // Get rotation
    camera->MoveForward(3.5f);
    camera->RotateFirstPerson_OY(myPlayer.getRotationAngle());
    camera->MoveForward(-3.5f);

    // Player
    RenderMesh(meshes[myPlayer.getObjectName()], shaders["VertexColor"], modelMatrix, camera);
    
    // First enemy
    enemy_1.carMovement(modelMatrix, MainPoints);
    RenderMesh(meshes[enemy_1.getObjectName()], shaders["VertexColor"], modelMatrix, camera);

    // Second enemy
    enemy_2.carMovement(modelMatrix, MainPoints);
    RenderMesh(meshes[enemy_2.getObjectName()], shaders["VertexColor"], modelMatrix, camera);

    // Third enemy
    enemy_3.carMovement(modelMatrix, MainPoints);
    RenderMesh(meshes[enemy_3.getObjectName()], shaders["VertexColor"], modelMatrix, camera);

    glClear(GL_DEPTH_BUFFER_BIT);
    glViewport(miniViewport.x, miniViewport.y, miniViewport.width, miniViewport.height);

    // --------------------------------------------------------- MINIMAP ---------------------------------------------------------
    minimap->Set(glm::vec3(myPlayer.getTranslation().x, 30, myPlayer.getTranslation().z), glm::vec3(myPlayer.getTranslation().x, 0, myPlayer.getTranslation().z), glm::vec3(-1, 0, -1));

    RenderScene(minimap);

    // Move after player
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(myPlayer.getTranslation().x, myPlayer.getTranslation().y, myPlayer.getTranslation().z);
    
    // Get rotation
    modelMatrix *= transform3D::Translate(0, 0.3, 0);
    modelMatrix *= transform3D::Translate(0.5, 0, 0);
    modelMatrix *= transform3D::RotateOY(myPlayer.getRotationAngle());
    modelMatrix *= transform3D::Translate(-0.5, 0, 0);
    
    // Player
    RenderMesh(meshes[myPlayer.getObjectName()], shaders["VertexColor"], modelMatrix, minimap);

    // First enemy
    enemy_1.carMovement(modelMatrix, MainPoints);
    RenderMesh(meshes[enemy_1.getObjectName()], shaders["VertexColor"], modelMatrix, minimap);

    // Second enemy
    enemy_2.carMovement(modelMatrix, MainPoints);
    RenderMesh(meshes[enemy_2.getObjectName()], shaders["VertexColor"], modelMatrix, minimap);

    // Third enemy
    enemy_3.carMovement(modelMatrix, MainPoints);
    RenderMesh(meshes[enemy_3.getObjectName()], shaders["VertexColor"], modelMatrix, minimap);
}

// Reder mesh
void Tema2::RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, implement::Camera* minimap)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(minimap->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}

// Calculate the area between three vectors
double AreaComputation(glm::vec3 vec1, glm::vec3 vec2, glm::vec3 vec3)
{
    glm::vec3 vec13 = glm::vec3(vec3.x - vec1.x, 0, vec3.z - vec1.z);
    glm::vec3 vec12 = glm::vec3(vec2.x - vec1.x, 0, vec2.z - vec1.z);
    return abs(double(vec12.x * vec13.z - vec12.z * vec13.x)) / 2;
}

// Check if point is inside a triangle
bool CheckIfPointIsInsideTriangle(glm::vec3 vec1, glm::vec3 vec2, glm::vec3 vec3, glm::vec3 PATH) {
    // The whole triangle
    double areaSum = AreaComputation(vec1, vec2, PATH);
    areaSum = areaSum + AreaComputation(vec1, vec3, PATH);
    areaSum = areaSum + AreaComputation(vec2, vec3, PATH);

    if (abs(AreaComputation(vec1, vec2, vec3) - areaSum) <= 0.001) {
        return true;
    }
    else {
        return false;
    }
}

// Check if the point is inside the path
bool Tema2::CheckIfPointIsInsidePath(glm::vec3 PATH)
{
    // For each point
    for (int i = 0; i < 70; i++) {

        if (CheckIfPointIsInsideTriangle(RedPoints[i], BluePoints[i], RedPoints[i + 1], PATH) == true ||
            CheckIfPointIsInsideTriangle(RedPoints[i], BluePoints[i + 1], BluePoints[i], PATH) == true ||
            CheckIfPointIsInsideTriangle(RedPoints[i], BluePoints[i + 1], RedPoints[i + 1], PATH) == true ||
            CheckIfPointIsInsideTriangle(RedPoints[i + 1], BluePoints[i + 1], BluePoints[i], PATH) == true ||
            CheckIfPointIsInsideTriangle(RedPoints[70], BluePoints[70], BluePoints[0], PATH) == true ||
            CheckIfPointIsInsideTriangle(RedPoints[70], BluePoints[0], RedPoints[0], PATH) == true) {
            return true;
        }
    }

    return false;
}

// Keyboard input
void Tema2::OnInputUpdate(float deltaTime, int mods)
{
    if (window->KeyHold(GLFW_KEY_W)) {
        // Try to set new coordinates
        glm::vec3 oldPosition = myPlayer.getTranslation();
        myPlayer.setNewTR_star(
            myPlayer.getnewTR_star().x - (myPlayer.getSpeed() / myPlayer.getSpeedReducer()) * sin(myPlayer.getRotationAngle()) * deltaTime,
            myPlayer.getnewTR_star().y - (myPlayer.getSpeed() / myPlayer.getSpeedReducer()) * cos(myPlayer.getRotationAngle()) * deltaTime);
        
        // If we are indeed out of bounds, move us back
        if (CheckIfPointIsInsidePath(glm::vec3(myPlayer.getnewTR_star().x + myPlayer.getOffset() * 2, 0, myPlayer.getnewTR_star().y +
            myPlayer.getOffset())) == true) {
            myPlayer.setTranslation(myPlayer.getnewTR_star().x, myPlayer.getTranslation().y, myPlayer.getnewTR_star().y);
        }
        else {
            myPlayer.setNewTR_star(oldPosition.x, oldPosition.z);
        }
    }

    if (window->KeyHold(GLFW_KEY_S)) {
        // Try to set new coordinates
        glm::vec3 oldPosition = myPlayer.getTranslation();
        myPlayer.setNewTR_star(
            myPlayer.getnewTR_star().x + (myPlayer.getSpeed() / myPlayer.getSpeedReducer()) * sin(myPlayer.getRotationAngle()) * deltaTime,
            myPlayer.getnewTR_star().y + (myPlayer.getSpeed() / myPlayer.getSpeedReducer()) * cos(myPlayer.getRotationAngle()) * deltaTime);

        // If we are indeed out of bounds, move us back
        if (CheckIfPointIsInsidePath(glm::vec3(myPlayer.getnewTR_star().x + myPlayer.getOffset() * 2, 0,
            myPlayer.getnewTR_star().y + myPlayer.getOffset())) == true) {
            myPlayer.setTranslation(myPlayer.getnewTR_star().x, myPlayer.getTranslation().y, myPlayer.getnewTR_star().y);
        } else {
            myPlayer.setNewTR_star(oldPosition.x, oldPosition.z);
        }
    }

    if (window->KeyHold(GLFW_KEY_A)) {
        if (window->KeyHold(GLFW_KEY_W)) {
            myPlayer.setRotationAngle(myPlayer.getRotationAngle() + deltaTime);
        }
        else if (window->KeyHold(GLFW_KEY_S)) {
            myPlayer.setRotationAngle(myPlayer.getRotationAngle() - deltaTime);
        }
        else {
            myPlayer.setRotationAngle(myPlayer.getRotationAngle() + deltaTime);
        }
    }

    if (window->KeyHold(GLFW_KEY_D)) {
        if (window->KeyHold(GLFW_KEY_W)) {
            myPlayer.setRotationAngle(myPlayer.getRotationAngle() - deltaTime);
        }
        else if (window->KeyHold(GLFW_KEY_S)) {
            myPlayer.setRotationAngle(myPlayer.getRotationAngle() + deltaTime);
        }
        else {
            myPlayer.setRotationAngle(myPlayer.getRotationAngle() - deltaTime);
        }
    }
}

// N/A
void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
}

void Tema2::OnKeyPress(int key, int mods)
{
}

void Tema2::OnKeyRelease(int key, int mods)
{
}

void Tema2::FrameEnd()
{
}

void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
}

void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}

void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema2::OnWindowResize(int width, int height)
{
}