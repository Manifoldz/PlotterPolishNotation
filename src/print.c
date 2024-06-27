#include "print.h"

void graph_output(char* postfix) {
    int flag = 1;
    double x_step = 4.0 * M_PI / (WIDTH - 1);
    double y_step = 2.0 / (HEIGHT - 1);

    for (int y = HEIGHT - 1; y >= 0 && flag == 1; y--) {
        for (int x = 0; x < WIDTH && flag == 1; x++) {
            double xValue = x_step * (double)x;
            double yValue = calc(postfix, xValue, &flag);

            int cur = (int)round((1 - yValue) / y_step);

            if (flag) {
                if (cur == y) {
                    printf("*");
                } else {
                    printf(".");  // Пустое пространство
                }
            } else {
                printf("Ошибка");
            }
        }
        printf("\n");
    }
}
