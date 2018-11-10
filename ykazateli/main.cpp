#include <iostream>
#include "stdio.h"

int main() {
    int a, b , *p1, *p2, *p3;
    scanf("%d\n", &a);
    scanf("%d\n", &b);
    p1 = &a;
    p2 = &b;
    printf("%d\n", *p1);
    printf("%d\n", *p2);
    p3 = &*p1;
    p1 = &*p2;
    p2 = &*p3;
    printf("%d\n", *p1);
    printf("%d\n", *p2);
    return 0;
}