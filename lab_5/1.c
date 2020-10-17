#include <stdio.h>

void input_array(int* array, int n);
void make_groups(int* array, int n);
int* find_minus(int* array, int n);
void sort_out(int* array, int n);
void output_array(int* array, int n);

int main()
{
    int n;
        printf("Please insert how many numbers there are \n");
        scanf("%d", &n);
        int array[n];

        if (n <= 0)
        {
            printf("not correct amount \n");
            return -1;
        }
        
        input_array(array, n);

        make_groups(array, n);
        sort_out(array, n);

        output_array(array, n);
        return 0;
}

void input_array(int* array, int n)
{
    printf("Please insert numbers \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (array + i));
    }
}

void make_groups(int* array, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (array[j-1] < array[j])
            {
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}

int* find_minus(int* array, int n)
{
    int i = 0;
    for (i = 0; i < n && array[i] >= 0; i++);
    return &array[i];
}

void sort_out(int* array, int n)
{
      for (int i = *find_minus(array, n) + 1; i < n; i++)
    {
        for (int j = *find_minus(array, n) + 1; j < n; j++)
        {
            if (array[j-1] > array[j])
            {
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}

void output_array (int* array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d%s", array[i], " ");
    printf("\n");
}
