#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "bignumber.h"
#include "custom_io.h"

static struct big_number *create_big_number(char *digits, bool is_negative) {
    assert(digits != NULL);
    
    struct big_number *number = malloc(sizeof(struct big_number));
    
    if (!number) {
        free(digits);
        return NULL;
    }

    number->length = strlen(digits);
    number->digits = calloc(number->length + 1, sizeof(char));
    number->negative = is_negative;
    
    if (!number->digits) {
        free(number);
        return NULL;
    }

    strcpy(number->digits, digits);

    return number;
}

struct big_number *read_big_number() {
    int size = 0;
    char *input = read_digits(&size);
    if (!input || size == 0) {
        free(input);
        return NULL;
    }

    bool is_negative = input[0] == '-';
    if (is_negative) {
        memmove(input, input + 1, size); // removing the negative sign
        size--; 
    }

    input[size] = '\0';

    return create_big_number(input, is_negative);
}

void destroy_big_number(struct big_number *number) {
    free(number->digits);
    free(number);
}