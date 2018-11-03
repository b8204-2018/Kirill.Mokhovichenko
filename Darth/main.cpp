#include <iostream>
#include <stdio.h>
#include "functionPoint.h"

int main() {
    float x, y;
    printf("%d\n","Введите координаты х и у")
    scanf("%x\n", &x);
    scanf("%y\n", &y);
    printf("%d", functionPoint(x, y));
    return 0;
}