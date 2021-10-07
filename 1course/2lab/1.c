#include <stdio.h>
#include <math.h>

float function(float x);

void print_head(void);
void insert(float *start, float *end, int *measures);
void calculate_numbers(float start, float end, float step);
void print_tail(void);

int main()
{
    float start;
    float end;

    int measures;

    float step;
    
    insert(&start, &end, &measures);

    if (end <= start)
    {
        printf("Wrong interval \n");
        return -1;
    }

    if (measures <= 0)
    {
        printf("Wrong amount of measures \n");
        return -1;
    }
    
    step = (end - start) / measures;

    print_head();
    calculate_numbers(start, end, step);    
    print_tail();
    
    return 0;
}

void insert(float *start, float *end, int *measures)
{
    printf("Please insert interval and measures \n");
    scanf("%f%f%d", start, end, measures);
}

float function(float x)
{
    return (tanf(x) * sqrt(x));
}

void print_head(void)
{
    printf("+++++++++++#+++++++++++ \n");
    printf("+    x     #    y     + \n");
    printf("+++++++++++#+++++++++++ \n");
}

void calculate_numbers(float start, float end, float step)
{
    for (float x = start; x < end; x += step)
    {
        if (x >= 0)
            printf("+ ");
        else
            printf("+ ");

        float y = function(x);
        printf("%8.3f #",x);
        if (y >= 0)
            printf(" ");
        else
            printf(" ");

        if (x >= 0)
            printf("%8.3f +\n", y);
        else
            printf(" none    +\n");
    } 
}

void print_tail(void)
{
    printf("+++++++++++#+++++++++++ \n");
}
