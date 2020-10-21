//0var
#include <stdio.h>
#include <stdlib.h>

void insert_size_mtrx(int* v, int*h);
int** alloc_mat(int n, int m);
void transform(int** matrix, int* mass, int m, int n);
void insert_mtrx(int** mtrx, int v, int h);
void get_min(int** mtrx, int* min ,int v, int h);
void get_max(int** mtrx, int* max, int v, int h);
void swap(int* a, int* b);
void print_mtrx(int** mtrx_changed, int v, int h);
void new_matrix(int** mtrx, int v, int h, int min, int max);

int main()
{
    //h - horizontal v - vertical
    int h;
    int v;
    insert_size_mtrx(&v, &h);

    int** mtrx = alloc_mat(v, h);
    insert_mtrx(mtrx, v, h);

    int min = mtrx[0][0];
    int max = mtrx[0][0];

    get_min(mtrx, &min, v, h);
    get_max(mtrx, &max, v, h);

    new_matrix(mtrx, v, h, min, max);

    print_mtrx(mtrx, v, h);

    return 0;
}

void insert_size_mtrx(int* v, int*h)
{
    printf("Insert the height and the vidth: \n");
    scanf("%d%d", v, h);
}

void transform(int** matrix, int* mass, int n, int m)
{
    for (int i = 0; i < n; i++)
        matrix[i] = mass + i * m;
}

int** alloc_mat(int n, int m)
{
    int* mas = (int*)calloc(n*m, sizeof(int));
    int** matrix = (int**)calloc(n, sizeof(int*));
    transform(matrix, mas, n, m);
    return matrix;
}

void insert_mtrx(int** mtrx, int v, int h)
{
    printf("Insert matrix: \n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < h; j++)
        {
            scanf("%d", &mtrx[i][j]);
        }
    }
}

void get_min(int** mtrx, int* min, int v, int h)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (*min > mtrx[i][j])
                *min = mtrx[i][j];
        }
    }
}

void get_max(int** mtrx, int* max, int v, int h)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (*max < mtrx[i][j])
                *max = mtrx[i][j];
        }
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void new_matrix(int** mtrx, int v, int h, int min, int max)
{
    for (int i = 0; i < v - 1; i++)
    {
        for(int j = 0; j < h - i - 1; j++)
        {
            if (mtrx[i][j] == min || mtrx[i][j] == max || mtrx[v - i - 1][h - j - 1] == min || mtrx[v - i - 1][h - j - 1] == max)
                swap(&mtrx[v - i - 1][h - j - 1], &mtrx[i][j]);
        }
    }
}

void print_mtrx(int** mtrx_changed, int v, int h)
{
    printf("New matrix: \n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < h; j++)
        {
            printf("%d ", mtrx_changed[i][j]);
        }
        printf("\n");
    }
}
