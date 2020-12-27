#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 400

char* make_place();
void input_string(char* s);
void output_string(char* s);
void free_string(char* s);
void without_spaces(char* s);
void remove_commas(char* s);
void remove_dots(char* s);
void find_word(char* string, char* word);
void split(char*** p_words, char* str, const char* symb);
void creating_dict(char** p_words, int* dict, int count);
void output_dict(char** p_words, int* dict, int count);

#endif
