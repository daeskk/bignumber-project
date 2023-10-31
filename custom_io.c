#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char *read_input() {
    char c;
    char *input = NULL;
    int capacity = 0, size = 0;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (size + 1 >= capacity) { 
            capacity = capacity == 0 ? 2 : capacity * 2;
            char *temp_input = realloc(input, capacity);
            if (!temp_input) {
                free(input);
                return NULL;
            }
            memset(temp_input + size, 0, capacity - size); 
            input = temp_input;
        }
        if (c == EOF && size == 0) { 
            free(input);
            return NULL;
        }
        input[size++] = c;
    }

    input[size] = '\0';

    return input;
}