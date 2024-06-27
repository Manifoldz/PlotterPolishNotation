#ifndef POLISH_NOTATION_H
#define POLISH_NOTATION_H

#include <stdio.h>
#include <string.h>

#include "stack.h"
int convert_polish(char *inputString, char *outputString);
char prefix_displacement(char **start);
int is_prefix(char sign);
void binar(char **slider_out, char slider, Node **root);
int get_priority(char sign);
int is_close_scobka(char **slider_out, Node **root);
int is_digit(char character);
int is_binar(char *sign);
void get_all(char **slider_out, Node **root);

#endif