#include "library.h"

int main()
{
    char* str = make_place();
    input_string(str);
    int n;
    input_size(&n);
    make_lines(str, n);
    free_string(str);
    return 0;
}
