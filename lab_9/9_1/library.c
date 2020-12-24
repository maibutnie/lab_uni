#include "library.h"

char* make_place(int size)
{
    return (char*)calloc(size + 1, sizeof(char));
}

void input_string(char* s)
{
    printf("Enter the string:\n");
    gets(s);
}

void output_string(char* s)
{
    printf("Word: %s", s);
}

void free_string(char* s)
{
    free(s);
}

void free_mas(char** mas)
{
    free(*mas);
    free(mas);
}

void remove_spaces(char* str, char* str2)
{
    int k = 0;
    int len = strlen(str) + 1;
    for (int i = 1; i < len; i++)
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

void without_spaces(char* s)
{
    char* prob;
    while ((prob = strstr(s, "  ")))
        strcpy(prob, prob + 1);
}

void remove_commas(char* s)
{
    char* prob;
    while ((prob = strstr(s, ", ")))
        strcpy(prob, prob + 1);
}

void remove_dots(char* s)
{
    char* prob;
    while ((prob = strstr(s, ". ")))
        strcpy(prob, prob + 1);
}

char* strsub(char* sub_s, char* s, int len)
{
    int i;
    for (i = 0; (i < len) && (sub_s[i] = s[i]); i++);
    if (i == len)
        sub_s[i] = 0;
    return sub_s;
}

int words_count(char* s, const char* symb)
{
    char* p = s;
    int count = 0;
    for (char* ps; (ps = strpbrk(p, symb)); p++)
    {
        if (ps != p)
        {
            count++;
            p = ps;
        }
    }
    if (strlen(p))
        count++;
    return count;
}

void split(char*** p_words, char* str, const char* symb)
{
    char* p = str;
    int count = words_count(str, symb);
    int index = 0;
    *p_words = (char**)calloc(count, sizeof(char*));

    for (char* ps; (ps = strpbrk(p, symb)); p++)
    {
        if (ps != p)
        {
            int len = ps - p;
            (*p_words)[index] =  (char*)calloc(strlen(p) + 1, sizeof(char));
            memcpy((*p_words)[index], p, len * sizeof(char));
            index++;
            p = ps;
        }
    }

    if (strlen(p))
    {
        (*p_words)[index] = (char*)calloc(strlen(p) + 1, sizeof(char));
        strcpy((*p_words)[index], p);
    }
}

void creating_dict(char** p_words, int* dict, int count)
{
    char* word = make_place(SIZE);
    for (int i = 0; i < count; i++)
    {
        word = p_words[i];
        if (strcmp(word, " ") != 0)
        {
            dict[i] = 1;
            for (int j = i + 1; j < count; j++)
            {
                if (strcmp(word, p_words[j]) == 0)
                {
                    dict[i]++;
                    p_words[j] = " ";
                }
            }
        }
    }
}

void output_dict(char** p_words, int* dict, int count)
{
    for (int i = 0; i < count; i++)
    {
        if ((dict[i] != 0) && (strcmp(p_words[i], " ") != 0))
        {
            output_string(p_words[i]);
            printf(" Amount: %d\n", dict[i]);
        }
    }
}
