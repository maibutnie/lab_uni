#include <stdio.h>
#include <stdlib.h>

void size_mtrx(int* n, int* m);
int** alloc_mat(int n, int m);
void transform(int** mtrx, int* mas, int n, int m);
void insert_mtrx(int** mtrx, int n, int m);
void mat_to_mas(int** mtrx, int* mas, int n, int m);
void swap(int* a, int* b);
void bubble_sort(int* a, int size);
void snake_sort(int** mtrx, int* mas, int n, int m);
void print_mat(int** mtrx, int n, int m);
void free_mat(int** mtrx);

int main()
{
    int n, m;
    size_mtrx(&n, &m);
    int** matrix = alloc_mat(n, m);
    insert_mtrx(matrix, n, m);
    printf("Old matrix: \n");
    print_mat(matrix, n, m);

    int* mas = (int*)calloc(n*m, sizeof(int));
    mat_to_mas(matrix, mas, n, m);
    int size = n * m;
    bubble_sort(mas, size);

    snake_sort(matrix, mas, n, m);

    printf("New matrix: \n");
    print_mat(matrix, n, m);
    free_mat(matrix);
    return 0;
}

void size_mtrx(int* n, int* m)
{
    printf("Insert the height and the width: \n");
    scanf("%d%d", n, m);
}

int** alloc_mat(int n, int m)
{
    int* mas = (int*)calloc(n*m, sizeof(int));
    int** matrix = (int**)calloc(n, sizeof(int*));
    transform(matrix, mas, n, m);
    return matrix;
}

void transform(int** matrix, int* mass, int n, int m)
{
    for (int i = 0; i < n; i++)
        matrix[i] = mass + i * m;
}

void insert_mtrx(int** mtrx, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", *(mtrx + i) + j);
        }
    }
}

void mat_to_mas(int** mtrx, int* mas, int n, int m)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mas[temp] = mtrx[i][j];
            temp++;
        }
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* a, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (a[j - 1] < a[j])
                swap((a + j - 1), (a + j));
        }
    }
}

void snake_sort(int** mtrx, int* mas, int n, int m)
{
    int left_border = 0;
    int right_border = m - 1;
    int up_border = 0;
    int down_border = n - 1;
    //down 0 right 1 up 2 left 3
    int direction = 0;
    int temp = 0;
    while (temp < n * m)
    {
        switch (direction)
        {
            case 0:
                for (int i = up_border; i <= down_border; i++)
                {
                    mtrx[i][left_border] = mas[temp];
                    temp++;
                }
                left_border++;
                direction = 1;
                break;
            case 1:
                for (int i = left_border; i <= right_border; i++)
                {
                    mtrx[down_border][i] = mas[temp];
                    temp++;
                }
                down_border--;
                direction = 2;
                break;
            case 2:
                for (int i = down_border; i >= up_border; i--)
                {
                    mtrx[i][right_border] = mas[temp];
                    temp++;
                }
                right_border--;
                direction = 3;
                break;
            case 3:
                for (int i = right_border; i >= left_border; i--)
                {
                    mtrx[up_border][i] = mas[temp];
                    temp++;
                }
                up_border++;
                direction = 0;
                break;
        }
    }
}

void print_mat(int** mtrx, int n, int m)
{
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
