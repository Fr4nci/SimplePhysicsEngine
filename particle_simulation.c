#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define NUM_PARTICLES 1

// Vettore 2-D
typedef struct {
    float x;
    float y;
} Vector2;

typedef struct {
    Vector2 position;
    Vector2 velocity;
    float mass;
} Particle;

Particle particles[NUM_PARTICLES];

void InitializeParticles() {
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        particles[i].position = (Vector2){(float)rand() / RAND_MAX * 100, (float)rand() / RAND_MAX * 100};
        particles[i].velocity = (Vector2){0, 0};
        particles[i].mass = 1;
    }
    printf("Inizio\n");
}

void PrintParticles() {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        Particle *particle = &particles[i];
        printf("i-th particle [%i] (%.2f, %.2f)\n", i, particle->position.x, particle->position.y);
    }
}

Vector2 ComputeForce(Particle *particle) {
    return (Vector2){0, particle->mass * -9.81};
}

void RunSimulation() {
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
