#pragma once

#include <math.h>
#include <stdlib.h>
#include "raylib.h"
#include "models.h"

double angleBetween(int angle1, int angle2)
{
    if (angle1 > angle2)
    {
        return angle1 - angle2;
    }
    else
    {
        return angle2 - angle1;
    }
}

char isOpositeAngle(int angle, int otherAngle)
{
    if (angle == (otherAngle + 180))
    {
        return 1;
    }
    if (angle == (otherAngle - 180))
    {
        return 1;
    }

    return 0;
}

