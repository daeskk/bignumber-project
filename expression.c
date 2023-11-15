#include <stdlib.h>
#include <stdio.h>

#include "expression.h"
#include "helpers.h"

static struct big_number *add_positive_big_numbers(struct big_number *bg1, struct big_number *bg2) {
    int max_length = bg1->length > bg2->length ? bg1->length : bg2->length;
    char *result = calloc(max_length + 1, sizeof(char));

    int rest = 0;
    int i = 0;

    for (; i < max_length; i++) {
        int digit1 = i < bg1->length ? bg1->digits[i] - '0' : 0;
        int digit2 = i < bg2->length ? bg2->digits[i] - '0' : 0;

        int sum = digit1 + digit2 + rest;
        result[i] = (sum % 10) + '0';
        rest = sum / 10;
    }

    if (rest > 0) {
        result[i++] = rest + '0';
    }

    return create_big_number(result, i, false);
}

static struct big_number *subtract(struct big_number *bg1, struct big_number *bg2) {
    struct big_number *result = NULL;

    return result;
}

static struct big_number *multiply(struct big_number *bg1, struct big_number *bg2) {
    struct big_number *result = NULL;

    return result;
}

static struct big_number *add(struct big_number *bg1, struct big_number *bg2) {
    struct big_number *result = NULL;


    if (bg1->negative == bg1->negative) {
        result = add_positive_big_numbers(bg1, bg2);
    } else {
        if (bg1->length > bg2->length) {
            result = subtract(bg1, bg2);
        } else if (bg1->length < bg2->length) {
            result = subtract(bg2, bg1);
        } else {
            for (int i = 0; i < bg1->length; i++) {
                if (bg1->digits[i] > bg2->digits[i]) {
                    result = subtract(bg1, bg2);
                    break;
                } else if (bg1->digits[i] < bg2->digits[i]) {
                    result = subtract(bg2, bg1);
                    break;
                }
            }
        }
    }

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