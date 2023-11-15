#include <stdlib.h>
#include <stdio.h>

#include "expression.h"
#include "helpers.h"

// Processo de adição de números positivos
static struct big_number *add_positive_big_numbers(struct big_number *bg1, struct big_number *bg2) {
    int max_length = bg1->length > bg2->length ? bg1->length : bg2->length;
    char *result = calloc(max_length + 1, sizeof(char));

    int rest = 0;
    int i = 0;

    for (; i < max_length; i++) {
        int digit1 = i < bg1->length ? bg1->digits[bg1->length - i - 1] - '0' : 0;
        int digit2 = i < bg2->length ? bg2->digits[bg2->length - i - 1] - '0' : 0;

        int sum = digit1 + digit2 + rest;
        result[i] = (sum % 10) + '0';
        rest = sum / 10;
    }

    if (rest > 0) {
        result[i++] = rest + '0';
    }

    reverse_string(result);

    return create_big_number(result, i, false);
}

// Processo de subtração de números positivos
static struct big_number *subtract_positive_big_numbers(struct big_number *bg1, struct big_number *bg2) {
    int max_length = bg1->length > bg2->length ? bg1->length : bg2->length;
    char *result = calloc(max_length + 1, sizeof(char));

    int rest = 0;
    int i = 0;

    for (; i < max_length; i++) {
        int digit1 = i < bg1->length ? bg1->digits[bg1->length - i - 1] - '0' : 0;
        int digit2 = i < bg2->length ? bg2->digits[bg2->length - i - 1] - '0' : 0;

        int sub = digit1 - digit2 - rest;
        result[i] = (sub % 10) + '0';
        rest = sub / 10;
    }

    if (rest > 0) {
        result[i++] = rest + '0';
    }

    reverse_string(result);
    
    return create_big_number(result, i, false);
}


// Subtração - falta implementar sinais diferentes
static struct big_number *subtract(struct big_number *bg1, struct big_number *bg2) {
    struct big_number *result = NULL;
    if (bg1->negative == bg1->negative) {
        result = subtract_positive_big_numbers(bg1, bg2);
        result->negative = bg1->negative;
    }
    return result;
}


// Multiplicação - falta implementar
static struct big_number *multiply(struct big_number *bg1, struct big_number *bg2) {
    struct big_number *result = NULL;

    return result;
}

// Adição - caso seja entre dois números negativos, trata como positivos, para sinais diferentes subtrai o menor do maior
static struct big_number *add(struct big_number *bg1, struct big_number *bg2) {
    struct big_number *result = NULL;
    if (bg1->negative == bg1->negative) {
        result = add_positive_big_numbers(bg1, bg2);
        result->negative = bg1->negative;
    } else {
        if (bg1->length > bg2->length) {
            result = subtract(bg1, bg2);
            result->negative = bg1->negative;
        } else if (bg1->length < bg2->length) {
            result = subtract(bg2, bg1);
            result->negative = bg2->negative;
    }
    return result;
}

// Cria nova expressão
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

// Cálculo do resultado final - direciona para as funções corretas
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

// Libera a memória das expressões realizadas e números utilizados
void destroy_expression(struct expression *expression) {
    destroy_big_number(expression->numbers[0]);
    destroy_big_number(expression->numbers[1]);
    free(expression->result);
    free(expression);
}