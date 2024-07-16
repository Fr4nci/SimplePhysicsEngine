#ifndef RIGID_BODY_H
#define RIGID_BODY_H
#include "vector.h"

typedef struct{
    float width;
    float height;
    float mass;
    float momentOfInerzia;
} BoxShape;

typedef struct{
    Vector2 position;
    Vector2 linearVelocity;
    float angle;
    float angularVelocity;
    Vector2 force;
    float torque;
    BoxShape shape;
} RigidBody;

void CalculateBoxInerzia(BoxShape *boxShape);

#endif