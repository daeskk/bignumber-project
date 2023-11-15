#include <stdlib.h>
#include <stdio.h>

#include "expression.h"
#include "helpers.h"

static struct big_number *add(struct big_number *bg1, struct big_number *bg2) {
    struct big_number *result = NULL;

    return result;
}

static struct big_number *subtract(struct big_number *bg1, struct big_number *bg2) {
    struct big_number *result = NULL;

    return result;
}

static struct big_number *multiply(struct big_number *bg1, struct big_number *bg2) {
    struct big_number *result = NULL;

    return result;
}

struct expression *create_expression() {
    struct big_number *bg1 = read_big_number();
    struct big_number *bg2 = read_big_number();
    char op = getchar();
    getchar();

    struct expression *expression = malloc(sizeof(struct expression));

    expression->numbers[0] = bg1;
    expression->numbers[1] = bg2;
    expression->operation = convert_operation(op);
    expression->result = NULL;

    return expression;
}

void calculate_expression(struct expression *expression) {
    struct big_number *result = NULL;

    switch (expression->operation) {
        case ADDITION:
            result = add(expression->numbers[0], expression->numbers[1]);
            break;
        case SUBTRACTION:
            result = subtract(expression->numbers[0], expression->numbers[1]);
            break;
        case MULTIPLICATION:
            result = multiply(expression->numbers[0], expression->numbers[1]);
            break;
        default:
            break;
    }

    expression->result = result;
}


void destroy_expression(struct expression *expression) {
    destroy_big_number(expression->numbers[0]);
    destroy_big_number(expression->numbers[1]);
    free(expression->result);
    free(expression);
}