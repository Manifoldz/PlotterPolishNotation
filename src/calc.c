#include "calc.h"

void binary_operation(struct Stack* stack, char op) {
    double num2 = pop(stack);
    double num1 = pop(stack);

    switch (op) {
        case '+':
            push(stack, num1 + num2);
            break;
        case '-':
            push(stack, num1 - num2);
            break;
        case '*':
            push(stack, num1 * num2);
            break;
        case '/':
            push(stack, num1 / num2);
            break;
    }
}

void unar_operation(struct Stack* stack, char op, int* flag) {
    double num = pop(stack);
    switch (op) {
        case 's':
            push(stack, sin(num));
            break;
        case 'c':
            push(stack, cos(num));
            break;
        case 'r':
            if (num >= 0) {
                push(stack, sqrt(num));
            } else {
                *flag = 0;
            }
            break;
        case 't':
            push(stack, tan(num));
            break;
        case 'g':
            push(stack, 1 / tan(num));  // tan(M_PI/2 - x)
            break;
        case 'l':
            push(stack, log(num));
            break;
    }
}
// hello

double calc(const char* postfix, double x, int* flag) {
    struct Stack* stack = createStack(MAX_SIZE);
    int i = 0;
    while (postfix[i] != '\0' && flag) {
        char token[MAX_SIZE];
        int j = 0;
        while (postfix[i] != ' ' && postfix[i] != '\0') {
            token[j] = postfix[i];
            (j++);
            (i++);
        }
        token[j] = '\0';
        if (isDigit(token[0]) || (token[0] == 'x') || ((token[0] == '-') && (isDigit(token[1])))) {
            if (token[0] == 'x') {
                push(stack, x);
            } else {
                double operand = atof(token);
                push(stack, operand);
            }
        } else {
            if ((token[0] == '+') || (token[0] == '-') || (token[0] == '*') || (token[0] == '/')) {
                binary_operation(stack, token[0]);
            } else if ((token[0] == 's') || (token[0] == 'c') || (token[0] == 'r') || (token[0] == 't') ||
                       (token[0] == 'g') || (token[0] == 'l')) {
                unar_operation(stack, token[0], flag);

            } else {
                *flag = 0;
            }
        }
        if (postfix[i] == ' ') {
            i++;
        }
    }
    double ans = pop(stack);
    clear_stack(stack);
    return ans;
}