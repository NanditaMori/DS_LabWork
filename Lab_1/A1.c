//A1
#include <stdio.h>
#define pi 3.14

void main()
{
    float radius,area;
    printf("Enter radius of circle:");
    scanf("%f",&radius);
    area = pi*radius*radius;
    printf("Area of circle for radius %f = %f ",radius,area);
}