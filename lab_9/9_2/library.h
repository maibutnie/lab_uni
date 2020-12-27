#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100

char* make_place();
void input_string(char* s);
void free_string(char* s);
void input_size(int* n);
int size_word(char* a);
char* ftstrcpy(char** dest, const char* src, int count);
void make_lines(char* str, int n);

#endif
