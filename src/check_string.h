#ifndef CHECK_STRING_H
#define CHECK_STRING_H
#include <stdio.h>
#include <string.h>

#include "stack.h"

// int check_string(char * string);
// int check_func(char * string, int * count);
char* to_lower(char* string);
char* redact_string(char* string, char* red_string);
int check_string(char* string);
int num_div(char* string);

#endif
// hello
