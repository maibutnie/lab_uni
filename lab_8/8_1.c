#include <stdio.h>
#include <malloc.h>
#include "mystring.h"

void remove_spaces(char* str, char* str2)
{
    int k = 0;
    for (int i = 1; i < ftstrlen(str); i++)
    {
        if (str[i - 1] == ' ')
        {
            if (k == 0)
                continue;
            if (str[i] == ' ')
                continue;
            if (str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?')
                continue;
        }
        str2[k] = str[i - 1];
        k++;
    }
}

int main()
{
    int size = 10000;
    char* str = (char*)calloc(size + 1, sizeof(char));
    char* str2 = (char*)calloc(size + 1, sizeof(char));
    input_string(str);
    remove_spaces(str, str2);

    output_string(str2);
    free_string(str);
    free_string(str2);
    return 0;
}
