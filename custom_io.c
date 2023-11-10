#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char *read_digits(int *size) {
    int capacity = 0;
    char *input = NULL;
    char c;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (*size + 1 >= capacity) {
            int old_capacity = capacity;
            capacity = capacity == 0 ? 2 : capacity * 2;
            char *temp = realloc(input, (capacity + 1) * sizeof(char));

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

    input[*size] = '\0';

    return input;
}