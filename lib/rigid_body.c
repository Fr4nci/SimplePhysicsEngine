#include "../header/rigid_body.h"

void CalculateBoxInerzia(BoxShape *boxShape){
    float m = boxShape->mass;
    float w = boxShape->width;
    float h = boxShape->height;
    boxShape->momentOfInerzia = m * (w * w + h * h)/12; 
}