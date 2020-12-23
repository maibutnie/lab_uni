#include "library.h"

int main()
{
    char* str = make_place(size);
    char* suf1 = make_place(size);
    char* suf2 = make_place(size);
    input_string(str);
    printf("Enter suf which should be changed: \n");
    gets(suf1);
    printf("Enter suf we should change for: \n");
    gets(suf2);
    printf("Old string: \n");
    output_string(str);
    printf("New string: \n");
    char* temp = make_place(size);
    find_word(str, temp);
    replace(temp, suf1, suf2);
    str = ftstrins(str, temp);
    output_string(str);
    free_string(str);
    return 0;
}
