#include "../header/vector.h"
float CrossProduct(Vector2 v1, Vector2 v2){
    return(v1.x * v2.y + v1.y * v2.y);
}
float DotProduct(Vector2 v1, Vector2 v2){
    return(v1.x * v2.x + v1.y * v2.y);
}

Vector2 SumVectors(Vector2 v1, Vector2 v2){
    return (Vector2){v1.x + v2.x, v1.y + v2.y};
}