#ifndef MYSTRING_H
#define MYSTRING_H
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

char* replace(char* s, char* suf1, char* suf2)
{
    for (char* p = s; (p = ftstrstr(p, suf1)); p += ftstrlen(suf2))
    {
        ftstrdel(p, ftstrlen(suf1));
        ftstrins(p, suf2);
    }
    return s;
}

#endif
