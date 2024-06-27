#ifndef CALC_H
#define CALC_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#define MAX_SIZE 500

// Создание стека

struct Stack* createStack(unsigned size);
int isEmpty(struct Stack* stack);
double pop(struct Stack* stack);
int isDigit(char n);
void binary_operation(struct Stack* stack, char op);
void unar_operation(struct Stack* stack, char op, int* flag);
double calc(const char* postfix, double x, int* flag);

#endif
