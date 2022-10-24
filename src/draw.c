#pragma once

#include "raylib.h"
#include <math.h>
#include <stdlib.h>
#include "models.h"


void DrawEntity(Entity entity)
{
    if (!entity.positioned)
    {
        return;
    }
    // *
    switch (entity.type)
    {
    case TypeCircle:

        break;

    case TypeRectangle:
        DrawRectangleV(entity.position, entity.measurement, entity.color);
        break;
    default:
        break;
    }
}