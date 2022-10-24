#pragma once

#include "physics.c"

double myCos(double x);
double mySin(double x);
void physicsGravity(Entity *entity);
void addVelocity(Entity *entity, int angle, int velocity);
Vector2 resultantForceAndAngle(double f1, double a1, double f2, double a2);
