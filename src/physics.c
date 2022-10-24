#pragma once

#include "raylib.h"
#include <math.h>
#include <stdlib.h>
#include "models.h"

#define degreeByRadians (180.0 / M_PI)

double myCos(double x)
{
    return cos(x / degreeByRadians);
}

double mySin(double x)
{
    return sin(x / degreeByRadians);
}

void physicsGravity(Entity *entity)
{
}

void addVelocity(Entity *entity, int angle, int velocity)
{
    if (entity->angle == angle)
    {
        entity->velocity += velocity;
    }
    else if (isOpositeAngle(entity->angle, angle))
    {
        entity->velocity -= velocity;
    }
}

Vector2 resultantForceAndAngle(double f1, double a1, double f2, double a2)
{
    // *
    double a = angleBetween(a1, a2);

    // !
    double resultantForce = sqrt(f1 * f1 + f2 * 1 + 2 * f1 * f2 * cos(a / degreeByRadians));
    double resultantAngle = pow(tan((f2 * sin(a / degreeByRadians)) / (f1 + f2 * cos(a / degreeByRadians))), -1);

    Vector2 result = {resultantForce, resultantAngle};
    return result;
}
