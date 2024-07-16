#ifndef PARTICLE_H
#define PARTICLE_H
#include "vector.h"
typedef struct {
    Vector2 position;
    Vector2 velocity;
    float mass;
} Particle;

#endif