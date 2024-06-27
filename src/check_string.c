#include "check_string.h"

int check_func(char* string, int* count) {
    char* start = string + (*count);
    int flag = 1;
    if (string[*count] == ' ' || string[*count] == '.') {
        flag = 1;
    } else if ((string[*count] == '+') || (string[*count] == '-') || (string[*count] == '*') ||
               (string[*count] == '/')) {
        flag = 1;
    } else if ((strncmp(start, "sqrt", 4) == 0)) {
        *count += 3;

    } else if ((strncmp(start, "sin", 3) == 0) || (strncmp(start, "cos", 3) == 0) ||
               (strncmp(start, "tan", 3) == 0) || (strncmp(start, "ctg", 3) == 0)) {
        *count += 2;
    } else if ((strncmp(start, "ln", 2) == 0)) {
        *count += 1;
    } else {
        flag = 0;
    }
    return flag;
}

int brackets_check(const char* string, int count) {
    int flag = 0;
    int let = 0;
    while (string[count] != '\0' && flag == 0) {
        if (string[count] == ')') {
            flag = 1;
        } else {
            let += 1;
        }
        count++;
    }
    if (let == 1) {
        flag = 0;
    }

    return flag;
}

int check_string(char* string) {
    int count_left_bracket = 0;
    int count_right_bracket = 0;

    int count = 0;
    int flag = 1;
    while (string[count] != '\0' && flag == 1) {
        if (isDigit(string[count]) || (string[count] == 'x') || (string[count] == 'X')) {
            flag = 1;
        } else if (((string[count] == '.') && (!isDigit(string[count + 1])))) {
            flag = 0;
        } else if (string[count] == '(') {
            flag = brackets_check(string, count);
            count_left_bracket++;
        } else if (string[count] == ')') {
            count_right_bracket++;
        } else {
            flag = check_func(string, &count);
        }

        count++;
    }

    if (count_left_bracket != count_right_bracket) {
        flag = 0;
    }
    return flag;
}

char* to_lower(char* string) {
    int count = 0;
    while (string[count] != '\0') {
        if ((string[count] >= 'A') && (string[count] <= 'Z')) {
            string[count] += 32;
        }
        count++;
    }
    string[count] = '\0';

    return string;
}

char* redact_string(char* string, char* red_string) {
    int string_count = 0;
    int red_count = 0;

    while (string[string_count] != '\0') {
        if (isDigit(string[string_count]) && (((string[string_count + 1])) == 'x')) {
            red_string[red_count] = string[string_count];
            red_string[red_count + 1] = '*';
            red_count += 2;
            string_count++;
        } else if (string[string_count] == ' ') {
            string_count++;
        } else {
            red_string[red_count] = string[string_count];
            red_count += 1;
            string_count++;
        }
    }
    red_string[red_count] = '\0';

    return red_string;
}

int num_div(char* string) {
    int flag = 1;
    while ((*string) != '\0' && flag) {
        if ((*string) == '/' && (*(string + 1)) == '0') {
            flag = 0;
        }
        string++;
    }
    return flag;
}