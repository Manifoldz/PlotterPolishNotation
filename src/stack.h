#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node *next;

} Node;

void push_char(char input_val, Node **root);
char pop_char(Node **root);
void destroy(Node **root);
int is_empty(const Node *root);

struct Stack {
    int top;
    int size;
    double *expression;
};

int isEmpty(struct Stack *stack);
void push(struct Stack *stack, float item);
double pop(struct Stack *stack);
int isDigit(char n);
void clear_stack(struct Stack *stack);

#endif
