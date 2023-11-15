#ifndef __expression_H__
#define __expression_H__

#include <stdio.h>
#include "bignumber.h"

// Definição das operações que podem ser realizadas
enum operation {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
};

// Definição das expressões
struct expression {
    enum operation operation;
    struct big_number *numbers[2];
    struct big_number *result;
};

struct expression *create_expression();
void calculate_expression(struct expression *expression);
void destroy_expression(struct expression *expression);

// Define a operação a ser realizada de acordo com o sinal recebido
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

// Output da expressão final
#define PRINT_EXPRESSION(calc) do { \
    if ((calc) != NULL) { \
        PRINT_BIG_NUMBER((calc)->numbers[0]); \
        PRINT_BIG_NUMBER((calc)->numbers[1]); \
        printf("operation: %d\n", (calc)->operation); \
        PRINT_BIG_NUMBER((calc)->result); \
    } else { \
        printf("Null expression\n"); \
    } \
} while (0)

#endif