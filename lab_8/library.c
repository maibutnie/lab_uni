#include "library.h"

char* ftstrcpy(char* dest, const char* src)
{
    for (int i = 0; (dest[i] = src[i]); i++);
    return dest;
}

char* ftstrstr(char* s1, const char* s2)
{
    char* q, *p = s1, *qs = s2;
    int check = 1;
    while (*p && *qs && check)
    {
        for (q = p, qs = s2; *q && (*q == *qs); q++, qs++);
        if (!(*qs && *q))
            check = 0;
        else
            p++;
    }
    return *p ? p : NULL;
}

void input_string(char* s)
{
    printf("Enter the string:\n");
    gets(s);
}

void output_string(char* s)
{
    puts(s);
}

void free_string(char* s)
{
    free(s);
}

size_t ftstrlen(const char* str)
{
    int len;
    for (len = 0; str[len]; len++);
    return len;
}

char* ftstrcat(char* s1, char* s2)
{
    char* p;
    for (p = s1; *p; p++);
    for (int i = 0; (p[i] = s2[i]); i++);
    return s1;
}

char* ftstrins(char* s, char* sub_s)
{
    char* s_temp = malloc((ftstrlen(s) + 1) * sizeof(char));
    ftstrcpy(s_temp, s);
    ftstrcpy(s, sub_s);
    ftstrcat(s, s_temp);
    free(s_temp);
    return s;
}

char* ftstrdel(char* s, int count)
{
    if (ftstrlen(s) <= count)
        s[0] = '\0';
    else
        ftstrcpy(s, s + count);
    return s;
}

char* ftstrpbrk (char* str, const char* sym)
{
    char* p, *q;
    int check = 1;
    for (p = str; *p && check;)
    {
        for (q=sym; *q && *p != *q; q++);
        if (*p == *q)
            check = 0;
        else
            p++;
    }
    return *p ? p : 0;
}

char* strsub(char* sub_s, char* s, int len)
{
    int i;
    for (i = 0; (i < len) && (sub_s[i] = s[i]); i++);
    if (i == len)
        sub_s[i] = 0;
    return sub_s;
}

void find_word(char* string, char* word)
{
    char* p = string;
    char* ps = ftstrpbrk(string, " ");
    int len = ps - p;
    strsub(word, string, len + 1);
    string = ftstrdel(string, len);
}

char* replace(char* s, char* suf1, char* suf2)
{
    for (char* p = s; (p = ftstrstr(p, suf1)); p += ftstrlen(suf2))
    {
        ftstrdel(p, ftstrlen(suf1));
        ftstrins(p, suf2);
    }
    return s;
}

void remove_spaces(char* str, char* str2)
{
    int k = 0;
    for (int i = 1; i < ftstrlen(str) + 1; i++)
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

char* make_place()
{
    return (char*)calloc(size, sizeof (char));
}
