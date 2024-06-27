#include "polish_notation.h"

int convert_polish(char *inputString, char *outputString) {
    //модуль перевода в польскую нотацию
    Node *root = NULL;
    char *slider = inputString;
    char *slider_out = outputString;
    int is_mistake = 0;

    while (*slider && *slider != '\n' && !is_mistake) {
        // если число или переменная или унарный то сразу в выходную строку
        if (is_digit(*slider) || *slider == 'x' || is_binar(slider) == 2) {
            *slider_out = *slider;
            slider_out++;
        }
        // если бинарная, то запуск отдельной функции
        else if (is_binar(slider) == 1) {
            binar(&slider_out, *slider, &root);
        }
        // если закрывающая скобка, то запуск выброса до первой открывающей и чек ошибки
        else if (*slider == ')') {
            if (!is_close_scobka(&slider_out, &root)) {
                printf("скобки нет!");
                destroy(&root);
                is_mistake = 1;
            }
        } else if (*slider == '.') {
            *slider_out = *slider;
            slider_out++;
        }
        //если префиксная функция, то помещаем в стек
        else {
            char temp = prefix_displacement(&slider);
            if (temp == '?') {
                printf("ошибка");
                is_mistake = 1;
            } else if (temp == '(' || slider_out == outputString || *(slider_out - 1) == ' ')
                push_char(temp, &root);
            else if (temp != ' ') {
                *slider_out = ' ';
                slider_out++;
                push_char(temp, &root);
            }
        }
        slider++;
    }
    get_all(&slider_out, &root);
    *slider_out = '\0';

    return is_mistake;
}

char prefix_displacement(char **start) {
    //проверяет что функция правильная, если ок, то смещает слайдер на след элемент
    //сама возвращает код функции или вопрос при ошибке
    char res = '?';  //ошибочное
    if (strncmp(*start, "sin(", 4) == 0) {
        *start += 2;
        res = 's';
    } else if (strncmp(*start, "sqrt(", 5) == 0) {
        *start += 3;
        res = 'r';
    } else if (strncmp(*start, "cos(", 4) == 0) {
        *start += 2;
        res = 'c';
    } else if (strncmp(*start, "tan(", 4) == 0) {
        *start += 2;
        res = 't';
    } else if (strncmp(*start, "ctg(", 4) == 0) {
        *start += 2;
        res = 'g';
    } else if (strncmp(*start, "ln(", 3) == 0) {
        *start += 1;
        res = 'l';
    } else if (**start == '(' || **start == ' ')
        res = **start;
    return res;
}

int is_digit(char character) {
    //возвращает цифра ли символ
    int res = 0;
    if (character >= '0' && character <= '9') res = 1;
    return res;
}

int is_binar(char *sign) {
    //возвращает бинарна ли операция
    //и проверяет не унарный ли минус
    int res = 0;
    if (*sign == '+' || *sign == '*' || *sign == '/')
        res = 1;
    else if (*sign == '-') {
        do {
            sign--;
        } while (*sign == ' ');
        if (is_digit(*sign) || *sign == 'x')
            res = 1;
        else
            res = 2;  //унарный минус
    }
    return res;
}

int is_close_scobka(char **slider_out, Node **root) {
    //выброс элементов стека до скобки. Если не встретилась, возвращаем 0-ошибку.
    int flag = 0;
    while (!flag && !is_empty(*root)) {
        if ((*root)->value == '(') {
            pop_char(root);
            flag = 1;
        } else {
            **slider_out = ' ';
            (*slider_out)++;
            **slider_out = pop_char(root);
            (*slider_out)++;
        }
    }
    return flag;
}

int get_priority(char sign) {
    //возвращает приоритетность операций
    int res = 0;
    if (sign == '*' || sign == '/')
        res = 3;
    else if (sign == '+' || sign == '-')
        res = 2;
    return res;
}

void binar(char **slider_out, char slider, Node **root) {
    //функция выбрасывает в строку операции префиксные и >= приоритетом
    int flag = !is_empty(*root);
    while (flag && (get_priority((*root)->value) >= get_priority(slider) || is_prefix((*root)->value))) {
        char temp = pop_char(root);
        **slider_out = ' ';
        (*slider_out)++;
        **slider_out = temp;
        (*slider_out)++;
        flag = !is_empty(*root);
    }
    if (*(*slider_out - 1) != ' ') {
        **slider_out = ' ';
        (*slider_out)++;
    }
    push_char(slider, root);
}

int is_prefix(char sign) {
    //возвращает 1 для префиксных операций
    int res = 0;
    if (sign == 's' || sign == 'c' || sign == 'r' || sign == 't' || sign == 'g' || sign == 'l') res = 1;
    return res;
}

void get_all(char **slider_out, Node **root) {
    //остатки стека выкидываем в выходную строку
    while (!is_empty(*root)) {
        **slider_out = ' ';
        (*slider_out)++;
        **slider_out = pop_char(root);
        (*slider_out)++;
    }
}