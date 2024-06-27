#include "stack.h"

struct Stack *createStack(unsigned size) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->expression = (double *)malloc(stack->size * sizeof(double));
    return stack;
}

// Проверка на пустоту стека
int isEmpty(struct Stack *stack) { return stack->top == -1; }

// Добавление элемента в стек
void push(struct Stack *stack, float item) { stack->expression[++stack->top] = item; }

// Извлечение элемента из стека
double pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->expression[stack->top--];
    }
    return 0.0;
}

void clear_stack(struct Stack *stack) {
    free(stack->expression);
    free(stack);
}

int isDigit(char n) { return ((n >= '0') && (n <= '9')); }

void push_char(char input_val, Node **root) {
    // добавить в стек
    Node *new = malloc(sizeof(Node));
    new->value = input_val;
    new->next = *root;
    *root = new;
}

char pop_char(Node **root) {
    // вытащить символ из стека
    char character = '\0';
    if (!is_empty(*root)) {
        Node *poped = *root;
        character = poped->value;
        *root = poped->next;
        free(poped);
    }
    return character;
}

void destroy(Node **root) {
    // просто чистка стека
    while (*root != NULL) {
        Node *temp = (*root)->next;
        free(*root);
        root = &temp;
    }
}

int is_empty(const Node *root) { return root == NULL; }
