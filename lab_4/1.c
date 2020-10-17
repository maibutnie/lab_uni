#include <stdio.h>

void input_array(int* array, int n);

int* minimal(int* array, int n);
int* maximum(int* array, int n);
int* search(int* array, int n, int elem);

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

        int* min = minimal(array, n);
        int* max = maximum(array, n);

        int elem = (*min + *max) / 2;

        int* sum = search(array,n, elem);

        *sum -= *max;
        printf("%d\n", *sum);

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

int* minimal(int* array, int n)
{
    int* min = array;
    for (int i = 0; i < n; i++)
    {
        if (*min > *(array + i))
            min = array + i;
    }
    return min;
}

int* maximum(int* array, int n)
{
    int* max = array;
    for (int i = 0; i < n; i++)
    {
        if (*max < *(array + i))
            max = array + i;
    }
    return max;
}

int* search(int* array, int n, int elem)
{
    int temp = 0; //сделала через темп потому что иначе ничерта не получалось а как по дургому не понимаю
    int* sum = &temp;
    for (int i = 0; i < n; i++)
    {
        if (*(array + i) > elem)
            *sum += *(array + i);
    }
    return sum;
}
