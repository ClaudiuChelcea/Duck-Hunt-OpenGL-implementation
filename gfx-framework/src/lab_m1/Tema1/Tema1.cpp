#include "Tema1.h"

using namespace std;
using namespace m1;

Tema1::Tema1() = default;
Tema1::~Tema1() = default;

#define SHOW_HITBOX false
#define SHOW_GROUND true

void Tema1::Init()
{
    // Set window
    resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    // Initialize angularStep
    angularStep = 0;

    // For randomization
    srand(time(NULL));

    // Create list of spawnpoints
    for (int yPos = 50; yPos <= 100; yPos = yPos + 10) {
        for (int xPos = 50; xPos <= 600; xPos = xPos + 25) {
            my_duck_manager.getSpawnPoints().push_back(std::make_pair(xPos, yPos));
        }
    }

    // Set an initial random spawn point from the list
    int spawnPointIndex = rand() % my_duck_manager.getSpawnPoints().size();
    my_duck_manager.setSpawnPoint(my_duck_manager.getSpawnPoints().at(spawnPointIndex));
   
    // Create duck
    my_duck_manager.createDuck(std::make_pair(my_duck_manager.getSpawnPoint().first, my_duck_manager.getSpawnPoint().second));
    my_duck_manager.getDuckAlive();
    AddMeshToList(my_duck_manager.getDuckAlive()->getBody());
    AddMeshToList(my_duck_manager.getDuckAlive()->getWingLeft());
    AddMeshToList(my_duck_manager.getDuckAlive()->getWingRight());
    AddMeshToList(my_duck_manager.getDuckAlive()->getHead());
    AddMeshToList(my_duck_manager.getDuckAlive()->getBeak());
    AddMeshToList(my_duck_manager.getDuckAlive()->getHitbox());
    AddMeshToList(my_duck_manager.getDuckAlive()->getEyeLeft());
    AddMeshToList(my_duck_manager.getDuckAlive()->getEyeLeftPupil());
    AddMeshToList(my_duck_manager.getDuckAlive()->getEyeRight());
    AddMeshToList(my_duck_manager.getDuckAlive()->getEyeRightPupil());

    // Create model matrix
    modelMatrix = glm::mat3 { 1 };

    // Wings movement
    angularStepIncreasing = true;

    // Set starting translation
    my_duck_manager.getDuckAlive()->setTranslateX(0);
    my_duck_manager.getDuckAlive()->setTranslateY(0);

    // Set random travelling angle between 25* and 135*, but not between 85 and 95
    // Also randomly (based if the result from rand is even or odd, go right or left
    int movingAngle = rand() % 110 + 25;
    while (movingAngle >= 85 && movingAngle <= 95) {
        movingAngle = rand() % 110 + 25;
    }
    my_duck_manager.getDuckAlive()->setTravellingAngle(movingAngle);
    my_duck_manager.getDuckAlive()->setDuckAngle(my_duck_manager.getDuckAlive()->getTravellingAngle() + 135);

    // Create UI
    AddMeshToList(my_UI.getGround());
    AddMeshToList(my_UI.getSky());
    AddMeshToList(my_UI.getLife1());
    AddMeshToList(my_UI.getLife2());
    AddMeshToList(my_UI.getLife3());
    AddMeshToList(my_UI.getBullet1());
    AddMeshToList(my_UI.getBullet2());
    AddMeshToList(my_UI.getBullet3());
    AddMeshToList(my_UI.gethealthBarBorder());
    AddMeshToList(my_UI.gethealthProgressBar());
    AddMeshToList(my_UI.getTree1trunk());
    AddMeshToList(my_UI.getTree1crown());
    AddMeshToList(my_UI.getTree2trunk());
    AddMeshToList(my_UI.getTree2crown());

    // Progress bar
    progressBarGoal = 210.0f;
    progressBarIncrement = progressBarGoal / ducksWantedToKill;
}

void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::Update(float deltaTimeSeconds)
{
    // Game over
    if (my_duck_manager.getDuckAlive()->getLivesCount() == 0 || ducksKilled == 15) {
        duckDead = true;

        // Put the duck in the middle of the screen and keep coordinates
        my_duck_manager.getDuckAlive()->setTranslateX(resolution.x / 2 - my_duck_manager.getSpawnPoint().first);
        my_duck_manager.getDuckAlive()->setTranslateY(resolution.y / 2 - my_duck_manager.getSpawnPoint().second + 150);

        // Rotate it infinitely
        my_duck_manager.getDuckAlive()->setTravellingAngle(my_duck_manager.getDuckAlive()->getTravellingAngle() + deltaTimeSeconds * 100);
        my_duck_manager.getDuckAlive()->setDuckAngle(my_duck_manager.getDuckAlive()->getTravellingAngle() + 135);
    }

    // Lives
    glm::mat3 body_part = glm::mat3(1);
    body_part = transform2D::Translate(1025.0f, 650.0f);
    if (my_duck_manager.getDuckAlive()->getLivesCount() >= 3) {
        RenderMesh2D(meshes[my_UI.getLife1String()], shaders["VertexColor"], body_part);
    }

    body_part *= transform2D::Translate(100.0f, 0.0f);
    if (my_duck_manager.getDuckAlive()->getLivesCount() >= 2) {
        RenderMesh2D(meshes[my_UI.getLife2String()], shaders["VertexColor"], body_part);
    }

    body_part *= transform2D::Translate(100.0f, 0.0f);
    if (my_duck_manager.getDuckAlive()->getLivesCount() >= 1) {
        RenderMesh2D(meshes[my_UI.getLife3String()], shaders["VertexColor"], body_part);
    }

    // Bullets
    body_part = glm::mat3(1);
    body_part = transform2D::Translate(1015.0f, 550.0f);
    if (my_duck_manager.getDuckAlive()->getBulletsCount() >= 3) {
        RenderMesh2D(meshes[my_UI.getBullet1String()], shaders["VertexColor"], body_part);
    }

    body_part *= transform2D::Translate(100.0f, 0.0f);
    if (my_duck_manager.getDuckAlive()->getBulletsCount() >= 2) {
        RenderMesh2D(meshes[my_UI.getBullet2String()], shaders["VertexColor"], body_part);
    }

    body_part *= transform2D::Translate(100.0f, 0.0f);
    if (my_duck_manager.getDuckAlive()->getBulletsCount() >= 1) {
        RenderMesh2D(meshes[my_UI.getBullet3String()], shaders["VertexColor"], body_part);
    }

    // Healthbar
    body_part *= transform2D::Translate(-200.0f, -50.0f);
    RenderMesh2D(meshes[my_UI.gethealthBarBorderString()], shaders["VertexColor"], body_part);
    body_part *= transform2D::Translate(7.0f, 2.5f);
    RenderMesh2D(meshes[my_UI.gethealthProgressBarString()], shaders["VertexColor"], body_part);

    // Ground
    body_part = glm::mat3(1);
    #if SHOW_GROUND
    RenderMesh2D(meshes[my_UI.getGroundString()], shaders["VertexColor"], body_part);
    #endif

    // Trees
    body_part = glm::mat3(1);
    body_part = transform2D::Translate(200.0f, 500.0f);
    RenderMesh2D(meshes[my_UI.getTree1crownString()], shaders["VertexColor"], body_part);
    body_part *= transform2D::Translate(-35.0f, -200.0f);
    RenderMesh2D(meshes[my_UI.getTree1trunkString()], shaders["VertexColor"], body_part);
    body_part *= transform2D::Translate(900.0f, 200.0f);
    RenderMesh2D(meshes[my_UI.getTree2crownString()], shaders["VertexColor"], body_part);
    body_part *= transform2D::Translate(-35.0f, -200.0f);
    RenderMesh2D(meshes[my_UI.getTree2trunkString()], shaders["VertexColor"], body_part);

    if (pauseGame == false && duckDead == false) {
        // Increment time
        my_duck_manager.getDuckAlive()->setTimeAlive(my_duck_manager.getDuckAlive()->getTimeAlive() + deltaTimeSeconds);

        // Evading
        if ((my_duck_manager.getDuckAlive()->getTimeAlive() > my_duck_manager.getDuckAlive()->getTimeAliveLimit() ||
            my_duck_manager.getDuckAlive()->getBulletsCount() <= 0) && my_duck_manager.getDuckAlive()->getWasShot() == false) {

            // Go up
            my_duck_manager.getDuckAlive()->setEvading(true);
            my_duck_manager.getDuckAlive()->setTravellingAngle(90);
            my_duck_manager.getDuckAlive()->setDuckAngle(my_duck_manager.getDuckAlive()->getTravellingAngle() + 135);

            // After it disappears, revive it elsewhere
            if (my_duck_manager.getDuckAlive()->getTranslateY() + my_duck_manager.getDuckAlive()->getGravityCenter().second - 150 > resolution.y) {

                // Set orientation
                int movingAngle = rand() % 110 + 25;
                while (movingAngle >= 85 && movingAngle <= 95) {
                    movingAngle = rand() % 110 + 25;
                }
                my_duck_manager.getDuckAlive()->setTravellingAngle(movingAngle);
                my_duck_manager.getDuckAlive()->setDuckAngle(my_duck_manager.getDuckAlive()->getTravellingAngle() + 135);

                // Set position
                int spawnPointIndex = rand() % my_duck_manager.getSpawnPoints().size();
                my_duck_manager.setSpawnPoint(my_duck_manager.getSpawnPoints().at(spawnPointIndex));
                my_duck_manager.getDuckAlive()->setTranslateX(my_duck_manager.getSpawnPoint().first);
                my_duck_manager.getDuckAlive()->setTranslateY(my_duck_manager.getSpawnPoint().second);

                // Lose life (only if it was not was)
                my_duck_manager.getDuckAlive()->setLivesCount(my_duck_manager.getDuckAlive()->getLivesCount() - 1);

                // Reset bullets
                my_duck_manager.getDuckAlive()->setBulletsCount(3);

                // Reset time
                my_duck_manager.getDuckAlive()->setTimeAlive(0.0f);

                // Reset evading
                my_duck_manager.getDuckAlive()->setEvading(false);
            }
        }

        // Shot
        if (my_duck_manager.getDuckAlive()->getWasShot() == true && my_duck_manager.getDuckAlive()->getEvading() == false) { // Duck is dead
            // Falling down
            my_duck_manager.getDuckAlive()->setTravellingAngle(-90);
            my_duck_manager.getDuckAlive()->setDuckAngle(my_duck_manager.getDuckAlive()->getTravellingAngle() + 135);

            // After it disappears, revive it elsewhere
            if (my_duck_manager.getDuckAlive()->getTranslateY() + my_duck_manager.getDuckAlive()->getGravityCenter().second + 150 < 0) {

                // Set orientation
                int movingAngle = rand() % 110 + 25;
                while (movingAngle >= 85 && movingAngle <= 95) {
                    movingAngle = rand() % 110 + 25;
                }
                my_duck_manager.getDuckAlive()->setTravellingAngle(movingAngle);
                my_duck_manager.getDuckAlive()->setDuckAngle(my_duck_manager.getDuckAlive()->getTravellingAngle() + 135);

                // Set position
                int spawnPointIndex = rand() % my_duck_manager.getSpawnPoints().size();
                my_duck_manager.setSpawnPoint(my_duck_manager.getSpawnPoints().at(spawnPointIndex));
                my_duck_manager.getDuckAlive()->setTranslateX(my_duck_manager.getSpawnPoint().first);
                my_duck_manager.getDuckAlive()->setTranslateY(my_duck_manager.getSpawnPoint().second);

                // Reset status
                my_duck_manager.getDuckAlive()->setWasShot(false);

                // Reset bullets
                my_duck_manager.getDuckAlive()->setBulletsCount(3);

                // Reset time
                my_duck_manager.getDuckAlive()->setTimeAlive(0.0f);

                // Increase ducks' speed after each 5 ducks (only after duck respawns)
                int speedIncreaseMultiplier = ducksKilled / 5;
                my_duck_manager.getDuckAlive()->setSpeed(my_duck_manager.getDuckAlive()->getInitialSpeed() + duckSpeedIncrease * speedIncreaseMultiplier);
            }
        }

        // Prevent going off-screen (very rare, but possible)
        if (my_duck_manager.getDuckAlive()->getTranslateY() + my_duck_manager.getDuckAlive()->getGravityCenter().second - 300 > resolution.y ||
            my_duck_manager.getDuckAlive()->getTranslateY() + my_duck_manager.getDuckAlive()->getGravityCenter().second + 300 < 0 ||
            my_duck_manager.getDuckAlive()->getTranslateX() + my_duck_manager.getDuckAlive()->getGravityCenter().first < -300 ||
            my_duck_manager.getDuckAlive()->getTranslateX() + my_duck_manager.getDuckAlive()->getGravityCenter().first > resolution.x + 300)
        {
            // Set orientation
            int movingAngle = rand() % 110 + 25;
            while (movingAngle >= 85 && movingAngle <= 95) {
                movingAngle = rand() % 110 + 25;
            }
            my_duck_manager.getDuckAlive()->setTravellingAngle(movingAngle);
            my_duck_manager.getDuckAlive()->setDuckAngle(my_duck_manager.getDuckAlive()->getTravellingAngle() + 135);

            // Set position
            int spawnPointIndex = rand() % my_duck_manager.getSpawnPoints().size();
            my_duck_manager.setSpawnPoint(my_duck_manager.getSpawnPoints().at(spawnPointIndex));
            my_duck_manager.getDuckAlive()->setTranslateX(my_duck_manager.getSpawnPoint().first);
            my_duck_manager.getDuckAlive()->setTranslateY(my_duck_manager.getSpawnPoint().second);

            // Reset time
            my_duck_manager.getDuckAlive()->setTimeAlive(0.0f);
        }

        // Calculate gravity center
        my_duck_manager.getDuckAlive()->setGravityCenter(std::make_pair(my_duck_manager.getSpawnPoint().first, my_duck_manager.getSpawnPoint().second));

        // Calculate translation (limit deltaTimeSeconds to not crash due to PC speed)
        if (deltaTimeSeconds < 0.5f && pauseGame == false && duckDead == false) {
            my_duck_manager.getDuckAlive()->setTranslateX(my_duck_manager.getDuckAlive()->getTranslateX() + deltaTimeSeconds * my_duck_manager.getDuckAlive()->getSpeed() * cos(GameManager::myMath::degreesToRadians(my_duck_manager.getDuckAlive()->getTravellingAngle())));
            my_duck_manager.getDuckAlive()->setTranslateY(my_duck_manager.getDuckAlive()->getTranslateY() + deltaTimeSeconds * my_duck_manager.getDuckAlive()->getSpeed() * sin(GameManager::myMath::degreesToRadians(my_duck_manager.getDuckAlive()->getTravellingAngle())));
        }

        // Check wall collisions
        if (my_duck_manager.getDuckAlive()->getTranslateX() + my_duck_manager.getDuckAlive()->getGravityCenter().first < 0 || my_duck_manager.getDuckAlive()->getTranslateX() + my_duck_manager.getDuckAlive()->getGravityCenter().first > resolution.x) {
            my_duck_manager.getDuckAlive()->setTravellingAngle(180 - my_duck_manager.getDuckAlive()->getTravellingAngle());
            my_duck_manager.getDuckAlive()->setDuckAngle(my_duck_manager.getDuckAlive()->getTravellingAngle() + 135);
        }
        else if (my_duck_manager.getDuckAlive()->getTranslateY() + my_duck_manager.getDuckAlive()->getGravityCenter().second < 0 || my_duck_manager.getDuckAlive()->getTranslateY() + my_duck_manager.getDuckAlive()->getGravityCenter().second > resolution.y) {
            my_duck_manager.getDuckAlive()->setTravellingAngle(-my_duck_manager.getDuckAlive()->getTravellingAngle());
            my_duck_manager.getDuckAlive()->setDuckAngle(my_duck_manager.getDuckAlive()->getTravellingAngle() + 135);
        }
    }

    // Create body
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(my_duck_manager.getDuckAlive()->getTranslateX(), my_duck_manager.getDuckAlive()->getTranslateY());
    modelMatrix *= transform2D::Translate(my_duck_manager.getSpawnPoint().first, my_duck_manager.getSpawnPoint().second);
    modelMatrix *= transform2D::Translate(+my_duck_manager.getDuckAlive()->getGravityCenter().first - my_duck_manager.getSpawnPoint().first, my_duck_manager.getDuckAlive()->getGravityCenter().second - my_duck_manager.getSpawnPoint().second);
    modelMatrix *= transform2D::Rotate(GameManager::myMath::degreesToRadians(my_duck_manager.getDuckAlive()->getDuckAngle()));
    modelMatrix *= transform2D::Translate(-my_duck_manager.getDuckAlive()->getGravityCenter().first + my_duck_manager.getSpawnPoint().first, -my_duck_manager.getDuckAlive()->getGravityCenter().second + my_duck_manager.getSpawnPoint().second);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getBodyString()], shaders["VertexColor"], modelMatrix);

    // Hitbox
    #if SHOW_HITBOX
    body_part = modelMatrix;
    body_part *= transform2D::Rotate(GameManager::myMath::degreesToRadians(-45));
    body_part *= transform2D::Translate(-65, -100);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getHitboxString()], shaders["VertexColor"], body_part);
    #endif

    // Eye left
    body_part = modelMatrix;
    body_part *= transform2D::Scale(0.4f, 0.4f);
    body_part *= transform2D::Translate(my_duck_manager.getDuckAlive()->getEyeLeftBodyOffsetPupil().first, my_duck_manager.getDuckAlive()->getEyeLeftBodyOffsetPupil().second);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getEyeLeftStringPupil()], shaders["VertexColor"], body_part);
    body_part = modelMatrix;
    body_part *= transform2D::Scale(0.4f, 0.4f);
    body_part *= transform2D::Translate(my_duck_manager.getDuckAlive()->getEyeLeftBodyOffset().first, my_duck_manager.getDuckAlive()->getEyeLeftBodyOffset().second);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getEyeLeftString()], shaders["VertexColor"], body_part);

    // Eye right
    body_part = modelMatrix;
    body_part *= transform2D::Scale(0.4f, 0.4f);
    body_part *= transform2D::Translate(my_duck_manager.getDuckAlive()->getEyeRightBodyOffsetPupil().first, my_duck_manager.getDuckAlive()->getEyeRightBodyOffsetPupil().second);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getEyeRightStringPupil()], shaders["VertexColor"], body_part);
    body_part = modelMatrix;
    body_part *= transform2D::Scale(0.4f, 0.4f);
    body_part *= transform2D::Translate(my_duck_manager.getDuckAlive()->getEyeRightBodyOffset().first, my_duck_manager.getDuckAlive()->getEyeRightBodyOffset().second);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getEyeRightString()], shaders["VertexColor"], body_part);

    // Create head
    body_part = modelMatrix;
    body_part *= transform2D::Scale(0.4f, 0.4f);
    body_part *= transform2D::Translate(my_duck_manager.getDuckAlive()->getHeadBodyOffset().first, my_duck_manager.getDuckAlive()->getHeadBodyOffset().second);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getHeadString()], shaders["VertexColor"], body_part);

    // Wing rotation step
    if (angularStepIncreasing) {
        angularStep += deltaTimeSeconds;
        if (angularStep > 0.5)
            angularStepIncreasing = false;
    }
    else {
        angularStep -= deltaTimeSeconds;
        if (angularStep <= 0)
            angularStepIncreasing = true;
    }

    // Right wing
    body_part = modelMatrix;
    body_part *= transform2D::Translate(my_duck_manager.getDuckAlive()->getRightWingBodyOffset().first, my_duck_manager.getDuckAlive()->getRightWingBodyOffset().second);
    body_part *= transform2D::Translate(22.5, 22.5);
    body_part *= transform2D::Rotate(angularStep);
    body_part *= transform2D::Translate(-22.5, -22.5);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getWingRightString()], shaders["VertexColor"], body_part);

    // Left wing
    body_part = modelMatrix;
    body_part *= transform2D::Translate(my_duck_manager.getDuckAlive()->getLeftWingBodyOffset().first, my_duck_manager.getDuckAlive()->getLeftWingBodyOffset().second);
    body_part *= transform2D::Translate(22.5, 22.5);
    body_part *= transform2D::Rotate(-angularStep);
    body_part *= transform2D::Translate(-22.5, -22.5);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getWingLeftString()], shaders["VertexColor"], body_part);

    // Beak
    body_part = modelMatrix;
    body_part *= transform2D::Translate(my_duck_manager.getDuckAlive()->getBeakBodyOffset().first, my_duck_manager.getDuckAlive()->getBeakBodyOffset().second);
    RenderMesh2D(meshes[my_duck_manager.getDuckAlive()->getBeakString()], shaders["VertexColor"], body_part);

    // Sky
    body_part = glm::mat3(1);
    body_part = transform2D::Translate(0.0f, 300.0f);
    RenderMesh2D(meshes[my_UI.getSkyString()], shaders["VertexColor"], body_part);

    std::cout << "trX: " << my_duck_manager.getDuckAlive()->getTranslateX() << " trY: " << my_duck_manager.getDuckAlive()->getTranslateY() << std::endl;
}

void Tema1::FrameEnd()
{
}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
    // Restart game
    if (key == GLFW_KEY_P) {
        pauseGame = !pauseGame;
    }
}


void Tema1::OnKeyRelease(int key, int mods)
{
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Remove bullet if we shoot ground
    if (mouseY >= 720 - 300 && my_duck_manager.getDuckAlive()->getBulletsCount() > 0 && pauseGame == false && duckDead == false) {
        my_duck_manager.getDuckAlive()->setBulletsCount(my_duck_manager.getDuckAlive()->getBulletsCount() - 1);
    }
    
    // If we have bullets
    // And if the duck is not evading
    // And if the duck is above the ground
    if (my_duck_manager.getDuckAlive()->getBulletsCount() > 0 && my_duck_manager.getDuckAlive()->getEvading() == false
        && mouseY <= 720 - 300 && pauseGame == false && duckDead == false && my_duck_manager.getDuckAlive()->getWasShot() == false) {
        // Reduce the number of bullets (if the duck was not shot already)
        if(my_duck_manager.getDuckAlive()->getWasShot() == false)
            my_duck_manager.getDuckAlive()->setBulletsCount(my_duck_manager.getDuckAlive()->getBulletsCount() - 1);

        // Check if we also kill duck
        float leftBottomCornerX = my_duck_manager.getSpawnPoint().first + my_duck_manager.getDuckAlive()->getTranslateX() - 65;
        float leftBottomCornerY = my_duck_manager.getSpawnPoint().second + my_duck_manager.getDuckAlive()->getTranslateY() - 100;
        float rightBottomCornerX = leftBottomCornerX + 130; // Add hitbox width
        float rightBottomCornerY = leftBottomCornerY;

        float leftTopCornerX = leftBottomCornerX;
        float leftTopCornerY = leftBottomCornerY + 180; // Add height
        float rightTopCornerX = rightBottomCornerX;
        float rightTopCornerY = rightBottomCornerY + 180; // Add height
        
        // Mouse Y is 0 to 720 from bottom to top
        if (mouseX >= leftBottomCornerX && mouseX <= rightBottomCornerX && mouseY >= 670 - leftTopCornerY && mouseY <= 670 - leftBottomCornerY) {
            // Update progress bar
            if (my_duck_manager.getDuckAlive()->getWasShot() == false) {
                if (progressBarIncrementStatus < progressBarGoal) {
                    progressBarIncrementStatus += progressBarIncrement;
                    *my_UI.gethealthProgressBarReference() = Rectangle::CreateRectangle("healthProgressBar", glm::vec3(0.0f, 0.0f, 0.0f), 20.0f, progressBarIncrementStatus, glm::vec3(1.0f, 1.0f, 1.0f), true);
                    AddMeshToList(my_UI.gethealthProgressBar());
                }
                else {
                    // Goal reached
                }
            }

            // Mark the duck as shot
            my_duck_manager.getDuckAlive()->setWasShot(true);

            // Increase count of ducks killed
            ++ducksKilled;
        }
    }
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}