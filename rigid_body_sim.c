#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <time.h>
#include "./header/vector.h"
#include "./header/rigid_body.h"

// TO COMPILE: USE gcc -o rigid_body_sim rigid_body_sim lib/rigid_body.c lib/vector.h

#define NUM_RIGID_BODIES 1
#define M_PI 3.1415
/* typedef struct {
    float x;
    float y;
} Vector2;
typedef struct{
    float width;
    float height;
    float mass;
    float momentOfInerzia;
} BoxShape;
*/
/* void CalculateBoxInerzia(BoxShape *boxShape){
    float m = boxShape->mass;
    float w = boxShape->width;
    float h = boxShape->height;
    boxShape->momentOfInerzia = m * (w * w + h * h)/12; 
} */

/* typedef struct{
    Vector2 position;
    Vector2 linearVelocity;
    float angle;
    float angularVelocity;
    Vector2 force;
    float torque;
    BoxShape shape;
} RigidBody;
*/
// Array globale di corpi rigidi
RigidBody rigidBodies[NUM_RIGID_BODIES];

void PrintRigidBody(){
    for(int i = 0; i < NUM_RIGID_BODIES; i++){
        RigidBody *body = &rigidBodies[i];
        printf("body [%i] r = (%.2f, %.2f), a = %.2f\n", i, body->position.x, body->position.y, body->angle);

    }
}

void InitializeRigidBody(){
    for (int i = 0; i < NUM_RIGID_BODIES; ++i) {
        RigidBody *body = &rigidBodies[i];
        body->position = (Vector2){ (rand()/RAND_MAX) * 100 , (rand()/RAND_MAX) * 100};
        body->angle = ((rand()/RAND_MAX) * 100)/360.f * M_PI * 2;
        body->linearVelocity = (Vector2){0, 0};
        body->angularVelocity = 0;
        
        BoxShape shape;
        shape.mass = 10;
        shape.width = 1 + (rand()/RAND_MAX) * 100;
        shape.height = 1 + (rand() / RAND_MAX) * 100;
        CalculateBoxInerzia(&shape);
        body->shape = shape;
    }
}

void ComputeForceAndTorque(RigidBody *rigidBody) {
    Vector2 f = (Vector2){0, 100};
    rigidBody->force = f;
    // r is the 'arm vector' that goes from the center of mass to the point of force application
    Vector2 r = (Vector2){rigidBody->shape.width / 2, rigidBody->shape.height / 2};
    rigidBody->torque = r.x * f.y - r.y * f.x;
}

void RunRigidBodySimulation() {
    float totalSimulationTime = 10; // The simulation will run for 10 seconds.
    float currentTime = 0; // This accumulates the time that has passed.
    float dt = 1; // Each step will take one second.
    
    InitializeRigidBody();
    PrintRigidBody();
    
    while (currentTime < totalSimulationTime) {
        
        for (int i = 0; i < NUM_RIGID_BODIES; ++i) {
            RigidBody *rigidBody = &rigidBodies[i];
            ComputeForceAndTorque(rigidBody);
            Vector2 linearAcceleration = (Vector2){rigidBody->force.x / rigidBody->shape.mass, rigidBody->force.y / rigidBody->shape.mass};
            rigidBody->linearVelocity.x += linearAcceleration.x * dt;
            rigidBody->linearVelocity.y += linearAcceleration.y * dt;
            rigidBody->position.x += rigidBody->linearVelocity.x * dt;
            rigidBody->position.y += rigidBody->linearVelocity.y * dt;
            float angularAcceleration = rigidBody->torque / rigidBody->shape.momentOfInerzia;
            rigidBody->angularVelocity += angularAcceleration * dt;
            rigidBody->angle += rigidBody->angularVelocity * dt;
        }
        
        PrintRigidBody();
        currentTime += dt;
    }
}

int main(){
    srand(time(NULL));
    RunRigidBodySimulation();
    return EXIT_SUCCESS;
}