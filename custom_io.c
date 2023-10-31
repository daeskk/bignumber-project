#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char *read_digits(int *size) {
    int capacity = 0;
    char *input = NULL, c;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (*size + 1 >= capacity) {
            capacity = capacity == 0 ? 2 : capacity * 2;
            char *temp = realloc(input, capacity);

            if (!temp) {
                free(input);
                return NULL;
            }
            
            memset(temp + *size, 0, capacity - *size);
            input = temp;
        }
        input[(*size)++] = c;
    }

    if (*size == 0 && c == EOF) {
        free(input);
        return NULL;
    }

    
    return input;
}