#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    float x;
    float y;
} Vector2;

// float CrossProduct(Vector2 v1, Vector2 v2);
float DotProduct(Vector2 v1, Vector2 v2);
Vector2 SumVectors(Vector2 v1, Vector2 v2);
Vector2 ScMultiplication(Vector2 v1, float b);
float norm(Vector2 v1);
#endif