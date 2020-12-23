#include <stdio.h>
#include "library.h"

int main()
{
    char* str = make_place();
    char* str2 = make_place();
    input_string(str);
    printf("Old string: \n");
    output_string(str);
    remove_spaces(str, str2);

    printf("New string: \n");
    output_string(str2);
    free_string(str);
    free_string(str2);
    return 0;
}
