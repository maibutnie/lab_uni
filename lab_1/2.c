#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_first(void);
void user_input(float *x, float *y);

float f1(float x);
float f2(float x);
float f3(float x);

void first_line_check(float x, float y, int *first_line);
void second_line_check(float x, float y, int *second_line);
void third_line_check(float x, float y, int *third_line);

int get_index(int first_line, int second_line, int third_line);

void print_result(char *output);

int main()
{
    char *output_list[] = { "in region 3", 
                            "on the line 3",
                            "in region 2",
                            "on the line 2",
                            "on the lines 2 and 3",
                            "on the line 2",
                            "in region 7",
                            "on the line 3",
                            "in region 1",
                            "on the line 1",
                            "on the lines 1 and 3",
                            "on the line 1",
                            "on the lines 1 and 2",
                            "error",
                            "on the lines 1 and 2",
                            "on the line 1",
                            "on the line 1 and 3",
                            "on the line 1",
                            "in region 4",
                            "on the line 3",
                            "error",
                            "on the line 2",
                            "on the line 2 and 3",
                            "on the line 2",
                            "in region 5",
                            "on the line 3",
                            "in region 6" };
    
    float x;
    float y;

    //point relative to line
    int first_line;
    int second_line;
    int third_line;

    int place;
    
    print_first();
    user_input(&x, &y);

    first_line_check(x, y, &first_line);
    second_line_check(x, y, &second_line);
    third_line_check(x, y, &third_line);

    int index = get_index(first_line, second_line, third_line);
    print_result(output_list[index]);
    
    return 0;
}

void print_first(void)
{
    printf("y = 2x + 2 \n");
    printf("y = 0.5x - 1 \n");
    printf("y = -x + 2 \n");
}

void print_result(char *output)
{
    printf("Point placed ");
    for (int i = 0; i < strlen(output); i++)
    {
        printf("%c", *(output + i));
    }
    printf("\n");
}

void user_input(float *x, float *y)
{   
    printf("Please insert coordinates of the point: \n");
    scanf("%f%f", x, y);
}

float f1(float x)
{
    return (2 * x + 2);
}

float f2(float x)
{
    return (x / 2 - 1);
}

float f3(float x)
{
    return (-x + 2);
}

// 0 - under, 1 - on, 2 - above

void first_line_check(float x, float y, int *first_line)
{
    if (f1(x) > y)
        *first_line = 0;
    else
    if (f1(x) == y)
        *first_line = 1;
    else
    if (f1(x) < y)
        *first_line = 2;    
}

void second_line_check(float x, float y, int *second_line)
{
    if (f2(x) > y)
        *second_line = 0;
    else
    if (f2(x) == y)
        *second_line = 1;
    else
    if (f2(x) < y)
        *second_line = 2;    
}

void third_line_check(float x, float y, int *third_line)
{
    if (f3(x) > y)
        *third_line = 0;
    else
    if (f3(x) == y)
        *third_line = 1;
    else
    if (f3(x) < y)
        *third_line = 2;    
}

int get_index(int first_line, int second_line, int third_line)
{
    return (first_line * 9 + second_line * 3 + third_line);
}
