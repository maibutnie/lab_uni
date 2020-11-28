// 1c and 2c should be redone but i have done it on a day of rk
#include <stdio.h>
#include <stdlib.h>

void insert_size_mtrx(int* w, int*h);
void insert_mtrx(int** mtrx, int w, int h);
int** alloc_mat(int n, int m);
void transform(int** matrix, int* mass, int m, int n);
void change_mtrx(int** mtrx_changed, int** mtrx, int w, int h);
void print_mtrx(int** mtrx_changed, int w, int h);
void free_mat(int** mtrx);

int main()
{
    int w;
    int h;
    insert_size_mtrx(&w, &h);

    int** mtrx = alloc_mat(w, h);
    insert_mtrx(mtrx, w, h);

    int **mtrx_changed = alloc_mat(h, w);
    change_mtrx(mtrx_changed, mtrx, w, h);
    print_mtrx(mtrx_changed, w, h);

    free_mat(mtrx);
    free_mat(mtrx_changed);
    return 0;
}

void insert_size_mtrx(int* w, int*h)
{
    printf("Insert the height and the width: \n");
    scanf("%d%d", w, h);
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

void insert_mtrx(int** mtrx, int w, int h)
{
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            scanf("%d", *(mtrx + i) + j);
        }
    }
}

void change_mtrx(int** mtrx_changed, int** mtrx, int w, int h)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            mtrx_changed[h - i - 1][w - j - 1] = mtrx[j][i];
        }
    }
}

void print_mtrx(int** mtrx_changed, int w, int h)
{
    printf("New matrix: \n");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%d ", mtrx_changed[i][j]);
        }
        printf("\n");
    }
}

void free_mat(int** mtrx)
{
    free(*mtrx);
    free(mtrx);
}
