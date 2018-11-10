#include <iostream>
#include <stdio.h>
#include "functionPoint.h"

int main() {
    float x, y;
    printf("%d\n", "Vvedite koordinati x i y");
    scanf("%f", &x);
    scanf("%f", &y);
    printf("%d", functionPoint(x, y));
    return 0;
}