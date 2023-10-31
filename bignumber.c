#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bignumber.h"

struct big_number *create_big_number(char *digits) {
    if (!digits) return NULL;
    
    struct big_number *number = malloc(sizeof(struct big_number));
    
    if (!number) return NULL;

    number->length = strlen(digits);
    number->digits = calloc(number->length + 1, sizeof(char));
    
    if (!number->digits) {
        free(number);
        return NULL;
    }

    strcpy(number->digits, digits);

    return number;
}

void destroy_big_number(struct big_number *number) {
    free(number->digits);
    free(number);
}