#pragma once

#include "components/simple_scene.h"
#include "Camera.h"
#include "CarEnemy.h"
#include "CarPlayer.h"
#include "MyRectangle.h"
#include "transform3D.h"

#define Z_FAR		(225.f)
#define Z_NEAR		(.01f)

namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
    public:
        Tema2();
        ~Tema2();

        bool isOrtho = false;
        void Init() override;

        struct Viewport
        {
            Viewport() : x(0), y(0), width(1), height(1) {}
            Viewport(int x, int y, int width, int height)
                : x(x), y(y), width(width), height(height) {}
            int width;
            int height;

            int x;
            int y;
        };

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;
        void RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, implement::Camera* minimap);
        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
        void RenderScene(implement::Camera* camera);

        // New methids
        bool CheckIfPointIsInsidePath(glm::vec3 PATH);
       
    protected:
        // Enemies
        /*
        Enemy
        * Position
        * Color
        * Ground offset
        * Fill rate
        * Speed
        * Trajectory offset
        * Object name
        * Start index
        */
        CarEnemy enemy_1 = {
            {0.0f, 0.0f, 0.0f},
            {0.0f, 0.0f, 0.0f}, 
            {0.0f, 0.2f, 0.0f}, 
            0.0f,
            10.0f,
            -0.7f,
            "obstacle1",
            0
        };

        CarEnemy enemy_2 = {
            {0.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 1.0f},
            {0.0f, 0.2f, 0.0f},
            0.0f,
            25.0f,
            0.0f,
            "obstacle2",
            0
        };

        CarEnemy enemy_3 = {
            {0.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 1.0f},
            {0.0f, 0.2f, 0.0f},
            0.0f,
            50.0f,
            0.5f,
            "obstacle3",
            0
        };

        // Rectangle
        MyRectangle myRectangle;

        // Points
        glm::vec3 MainPoints[71];
        glm::vec3 RedPoints[71];
        glm::vec3 BluePoints[71];
        glm::vec3 RedPath[71];
        glm::vec3 BluePath[71];
        float DistanceToRedPath = 0.5;
        float DistanceToBluePath = 1;
        float DistToRed = 0.4;
        float DistToBlue = 0.9;

        /* 
            Player
            * speed
            * car center,
            * offset
            * speed reducer
            * new coords if collision with border
            * translation
            * rotation angle
            * color
        */
        CarPlayer myPlayer =
        {
            25.0f,
            { 0.25f, 0.0f, 0.25f },
            0.25f,
            4.0f,
            { 0.0f, 0.0f },
            { 0.0f, 0.0f, 0.0f },
            0.0f,
            { 0.5f, 0.5f, 0.75f }
        };

        // Camera
        implement::Camera* camera = new implement::Camera(); // main camera
        implement::Camera *minimap = new implement::Camera(); // minimap
        glm::mat4 projectionMatrix;

        // Axis
        glm::vec3 UP = glm::vec3(0, 1, 0);
        
        // Computation
        glm::mat4 modelMatrix = glm::mat4(1);

        // Viewport
        Viewport miniViewport;
    };
} 