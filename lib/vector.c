#include "../header/vector.h"
#include <math.h>
/* float CrossProduct(Vector2 v1, Vector2 v2){
    return(v1.x * v2.y + v1.y * v2.y);
} */
float DotProduct(Vector2 v1, Vector2 v2){
    return(v1.x * v2.x + v1.y * v2.y);
}

Vector2 SumVectors(Vector2 v1, Vector2 v2){
    return (Vector2){v1.x + v2.x, v1.y + v2.y};
}

Vector2 ScMultiplication(Vector2 v1, float a){
    return (Vector2){a * v1.x, a * v1.y};
}

float norm(Vector2 v1){
    return(sqrt(DotProduct(v1)));
}