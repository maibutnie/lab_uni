#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#define size 1000

void remove_spaces(char* str, char* str2);
char* replace(char* s, char* suf1, char* suf2);
char* ftstrdel(char* s, int count);
char* ftstrins(char* s, char* sub_s);
char* ftstrcat(char* s1, char* s2);
size_t ftstrlen(const char* str);
void free_string(char* s);
void output_string(char* s);
void input_string(char* s);
char* ftstrstr(char* s1, const char* s2);
char* ftstrcpy(char* dest, const char* src);
char* make_place();
void find_word(char* string, char* word);

#endif
