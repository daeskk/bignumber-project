#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <memory.h>

#include "bignumber.h"

static struct big_number *create_big_number(char *digits, int size, bool is_negative) {
    assert(digits != NULL);
    
    struct big_number *number = malloc(sizeof(struct big_number));
    
    if (!number) {
        free(digits); return NULL;
    }

    number->negative = is_negative;
    number->length = size;
    number->digits = digits;

    return number;
}

static char *read_input(int *size) {
    int capacity = 0;
    char *input = NULL;
    char c;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (*size + 1 >= capacity) {
            int old_capacity = capacity;
            capacity = capacity == 0 ? 2 : capacity * 2;
            char *temp = realloc(input, capacity * sizeof(char));

            if (!temp) {
                free(input); return NULL;
            }
            memset(temp + old_capacity, 0, capacity - old_capacity);
            
            input = temp;
        }
        input[(*size)++] = c;
    }

    if (*size == 0 && c == EOF) {
        free(input); return NULL;
    }

    return input;
}

struct big_number *read_big_number() {
    int size = 0;
    char *input = read_input(&size);
    
    if (!input || size == 0) {
        free(input); return NULL;
    }

    bool is_negative = input[0] == '-';
    
    if (is_negative) {
        memmove(input, input + 1, size);
        size--; 
    }

    input[size] = '\0';

    return create_big_number(input, size, is_negative);
}

void destroy_big_number(struct big_number *number) {
    free(number->digits); 
    free(number);
}