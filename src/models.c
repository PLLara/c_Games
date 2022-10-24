#pragma once

#include "raylib.h"
#include <math.h>
#include <stdlib.h>

typedef struct
{
    void *list;
    int size;
} List;

typedef enum
{
    TypeCircle,
    TypeRectangle
} FormType;

typedef struct Entity Entity, *EntityAlt;
struct Entity
{
    int index;
    char positioned;
    // ! Objective
    FormType type;
    Vector2 position;
    Vector2 measurement;
    Color color;

    // ! Subjective
    int angle; // x px/s
    int velocity;  // yº
    void (*acceleration)(EntityAlt*)
};
