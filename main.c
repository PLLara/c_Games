#include "raylib.h"
#include <math.h>
#include <stdlib.h>
#include "src/models.h"
#include "src/draw.h"
#include "src/physics.h"

#define MAX_ENTITY_LIST_SIZE 100

char isOpositeAngle(int angle, int otherAngle);
double angleBetween(int angle1, int angle2);

int main(void)
{
    // Setup
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Colision ball");
    SetTargetFPS(60);

    // ! Initialization
    // // * Def  initial Vars
    Vector2 playerSize = {40, 50};
    int playerDistanceFromLeftBorder = 50;
    int playerDistanceFromTop = (screenHeight / 2) - (playerSize.y / 2);

    // // * Def structures
    Entity *entitieList = malloc((sizeof(Entity) * MAX_ENTITY_LIST_SIZE));
    Entity player = {
        0,
        1,
        TypeRectangle,
        {50, playerDistanceFromTop},
        {playerSize.x, playerSize.y},
        RED,
        90,
        1,
    };
    entitieList[0] = player;

    // // * Def final Vars
    List entities = {entitieList, 1};

    // Main game loop
    while (!WindowShouldClose())
    {
        // * Update
        for (int index = 0; index < entities.size; index++)
        {
            // ! Def vars
            Entity currentEntity = ((Entity *)entities.list)[index];
            double displacementX = currentEntity.velocity * myCos(currentEntity.angle);
            double displacementY = currentEntity.velocity * myCin(currentEntity.angle);

            // *
            ((Entity *)entities.list)[index].position.x += displacementX;
            ((Entity *)entities.list)[index].position.y -= displacementY;
        }


        // * Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int index = 0; index < entities.size; index++)
        {
            // ! Def vars
            Entity currentEntity = ((Entity *)entities.list)[index];
            DrawEntity(currentEntity);
        }
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}

void AddEntity(List *entities, Entity newEntity)
{
    // !
    Entity *entityList = (Entity *)entities->list;

    // *
    entityList[entities->size] = newEntity;
    entities->size = entities->size + 1;
}

void removeEntity(List *entities, int entityIndex)
{
}

