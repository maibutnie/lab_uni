//should be redone but i have done it on rk
#include <stdio.h>
#include <stdlib.h>

void insert_size(int* n, int* m);
void transform(int** mtrx, int* mas, int n, int m);
int** alloc_mat(int n, int m);
void insert_mat(int** mtrx, int n, int m);
int find_min(int** mtrx, int n, int m);
int find_max(int** mtrx, int n, int m);
void min_for_max(int** mtrx, int n, int m, int min, int max);
void print_mat(int** mtrx, int n, int m);
void free_mat(int** mtrx);

int main()
{
    int v, h;
    insert_size(&v, &h);

    int** matrix = alloc_mat(v, h);
    insert_mat(matrix, v, h);

    int min = find_min(matrix, v, h);
    int max = find_max(matrix, v, h);
    min_for_max(matrix, v, h, min, max);

    print_mat(matrix, v, h);
    free_mat(matrix);
    return 0;
}

void insert_size(int* n, int* m)
{
    printf("Insert height and width: ");
    scanf("%d%d", n, m);
}

void transform(int** mtrx, int* mas, int n, int m)
{
    for (int i = 0; i < n; i++)
        mtrx[i] = mas + i * m;
}

int** alloc_mat(int n, int m)
{
    int* mas = (int*) calloc(n * m, sizeof(int));
    int** mtrx = (int**) calloc(n, sizeof(int*));
    transform(mtrx, mas, n, m);
    return mtrx;
}

void insert_mat(int** mtrx, int n, int m)
{
    printf("Insert matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%d", *(mtrx + i) + j);
    }
}

int find_min(int** mtrx, int n, int m)
{
    int min = mtrx[0][0];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - i - 1; j++)
        {
            if (mtrx[i][j] < min)
                min = mtrx[i][j];
        }
    }
    return min;
}

int find_max(int** mtrx, int n, int m)
{
    int max = mtrx[n - 1][m - 1];
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = m - 1; j > n - 1 - i; j--)
        {
            if (mtrx[i][j] > max)
                max = mtrx[i][j];
        }
    }
    return max;
}

void min_for_max(int** mtrx, int n, int m, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mtrx[i][j] == min)
                mtrx[i][j] = max;
            else 
            if (mtrx[i][j] == max)
                mtrx[i][j] = min;
        }
    }
}

void print_mat(int** mtrx, int n, int m)
{
    printf("New matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", mtrx[i][j]);
        printf("%s", "\n");
    }
}

void free_mat(int** mtrx)
{
    free(*mtrx);
    free(mtrx);
}
