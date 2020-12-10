#include <stdio.h>
#include <malloc.h>
#include "mystring.h"

char* make_place(int size)
{
    char* s = (char*)calloc(size + 1, sizeof(char));
    return s;
}

int main()
{
    int size = 10000;
    char* str = make_place(size);
    char* suf1 = make_place(size);
    char* suf2 = make_place(size);
    input_string(str);
    printf("Enter suf which should be changed: \n");
    gets(suf1);
    printf("Enter suf to which we should change: \n");
    gets(suf2);
    printf("Old string: \n");
    output_string(str);
    replace(str, suf1, suf2);

    printf("New string: \n");
    output_string(str);
    free_string(str);
    return 0;
}
