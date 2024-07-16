#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> //this code is compiled from Ubuntu WSL so i can't use "windows.h"
#include <time.h>
#include "header/vector.h"
#include "header/particle.h"
#define NUM_PARTICLES 1

// Vettore 2-D
/* typedef struct {
    float x;
    float y;
} Vector2; //declaration a 2-D vector

typedef struct {
    Vector2 position;
    Vector2 velocity;
    float mass;
} Particle; //declaration of the type particle
*/
Particle particles[NUM_PARTICLES];

void InitializeParticles() { //Here i inizialize the position of the variable randomnly
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        particles[i].position = (Vector2){(float)rand() / RAND_MAX * 100, (float)rand() / RAND_MAX * 100};
        particles[i].velocity = (Vector2){0, 0};
        particles[i].mass = 1;
    }
    printf("Inizio\n");
}

void PrintParticles() { //This function print me the position of the various particles
    for (int i = 0; i < NUM_PARTICLES; i++) {
        Particle *particle = &particles[i];
        printf("i-th particle [%i] (%.2f, %.2f)\n", i, particle->position.x, particle->position.y);
    }
}

Vector2 ComputeForce(Particle *particle) { //this function compute the force of gravity on a particle
    return (Vector2){0, particle->mass * -9.81};
}

void RunSimulation() { //it really explicit of what this function does
    float TotalSimulationTime = 10;
    float currentTime = 0;
    float dt = 0.025;

    InitializeParticles();
    PrintParticles();

    while (currentTime < TotalSimulationTime) {
        usleep(dt * 1000000); // sleep for dt seconds (converted to microseconds)
        for (int i = 0; i < NUM_PARTICLES; i++) {
            Particle *particle = &particles[i];
            Vector2 force = ComputeForce(particle);
            Vector2 acceleration = (Vector2){force.x / particle->mass, force.y / particle->mass};
            particle->velocity.x += acceleration.x * dt;
            particle->velocity.y += acceleration.y * dt;
            particle->position.x += particle->velocity.x * dt;
            particle->position.y += particle->velocity.y * dt;
        }
        PrintParticles();
        currentTime += dt;
    }
}

int main(int argc, char** argv) {
    srand(time(NULL));
    RunSimulation();
    return 0;
}
