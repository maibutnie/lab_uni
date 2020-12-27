#include "library.h"

char* make_place()
{
    return (char*)calloc(size + 1, sizeof(char));
}

void input_string(char* s)
{
    printf("Enter the string:\n");
    gets(s);
}

void free_string(char* s)
{
    free(s);
}

void input_size(int* n)
{
    printf("Enter the size of the strings:\n");
    scanf("%d", n);
}

int size_word(char* a)
{
    int result = 0;
    for (int i = 0; a[i] != ' ' && a[i] != '\0' && a[i] != '\n'; i++)
        result++;
    return result;
}

char* ftstrcpy(char** dest, const char* src, int count)
{
    for (int i = 0; i < count; i++)
        (*dest)[i] = src[i];
    return *dest;
}

void make_lines(char* str, int n)
{
    int i = 0;
    int sizeA = strlen(str);
    while (str[i] && i < sizeA)
    {
        int right_lim = i + n;
        if (size_word(str + i) > n)
        {
            while (str[right_lim] != ' ' && str[right_lim] != '\0' && str[right_lim] != '\n')
            {
                right_lim++;
            }
        }
        else
        {
            if (right_lim > sizeA - 1)
            {
                right_lim = sizeA;
            }
            else
            if (str[right_lim + 1] != ' ' && str[right_lim + 1] != '\0' && str[right_lim + 1] != '\n')
            {
                while (str[right_lim] != ' ')
                {
                    right_lim--;
                }
            }
        }
        char *current = (char *) calloc(right_lim - i + 1, sizeof(char));
        ftstrcpy(&current, str + i, right_lim - i);
        puts(current);
        i = right_lim + 1;
        free(current);
    }
}
