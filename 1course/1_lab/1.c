#include <stdio.h>

int main()
{
    float x;
    float y;
    printf("Line equation: y = 0.5x + 1 \n");
    printf("Please insert coordinates of the point: \n");
    scanf("%f%f",&x,&y);
    if(y == x / 2 + 1)
        printf("Point is on the line \n");
    else if(y < x / 2 + 1)
        printf("Point is under the line \n");
    else
        printf("Point is above the line \n");
    return 0;
}
