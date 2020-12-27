#include "library.h"

int main()
{
    char* str = make_place();
    input_string(str);
    remove_dots(str);
    remove_commas(str);
    without_spaces(str);
    char** p_words;
    split(&p_words, str, " ");
    int count = words_count(str, " ");
    int dict[count];
    creating_dict(p_words, dict, count);
    output_dict(p_words, dict, count);
    free_string(str);
    free_mas(p_words);
    return 0;
}
