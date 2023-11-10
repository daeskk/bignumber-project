#ifndef __expression_H__
#define __expression_H__

#include "bignumber.h"

enum operation {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
};

struct expression {
    enum operation operation;
    struct big_number *numbers[2];
    struct big_number *result;
};

struct expression *create_expression();
void destroy_expression(struct expression *expression);

static inline enum operation convert_operation(char op) {
    switch (op) {
        case '+':
            return ADDITION;
        case '-':
            return SUBTRACTION;
        case '*':
            return MULTIPLICATION;
    }
}

#define PRINT_EXPRESSION(calc) do { \
    if ((calc) != NULL) { \
        PRINT_BIG_NUMBER((calc)->numbers[0]); \
        PRINT_BIG_NUMBER((calc)->numbers[1]); \
        printf("operation: %d\n", (calc)->operation); \
    } else { \
        printf("Null expression\n"); \
    } \
} while (0)

#endif