#include <math.h>

int functionPoint(float x,float y){
    float x, y, r;
    int point;
    r = sqrt(x * x + y * y);
    if (r > 10){
        point = 0;
    }
    if (r > 7 && r <= 10){
        point = 1;
    }
    if (r > 4 && r <= 7){
        point = 2;
    }
    if (r > 2 && r <= 4){
        point = 3;
    }
    if (r > 0 && r <= 2){
        point = 5;
    }
    return point;
}

