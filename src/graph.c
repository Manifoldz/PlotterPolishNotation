#include <math.h>
#include <stdio.h>

#include "calc.h"
#include "check_string.h"
#include "polish_notation.h"
#include "print.h"
#define LM 500

int main() {
    printf("Введите уравнение:");
    char string[LM] = {0};
    scanf("%255[^\n\r]", string);
    to_lower(string);
    char res_string[LM];
    redact_string(string, res_string);
    if (check_string(res_string) && num_div(res_string)) {
        printf("%s\n", res_string);
        char res[LM];
        int flag = convert_polish(res_string, res);
        if (flag == 0) {
            graph_output(res);
        }
    } else {
        printf("Ошибка");
    }
    return 0;
}

// sin(cos(2*x)) +
// sin(cos(-2*x)) +
// ln(-2x) +
// ln(2x) +
// sqrt(2x) +
// 2/x +
// x + 1
// -1 + x
// sin(x)*tan(x)+cos(3)
