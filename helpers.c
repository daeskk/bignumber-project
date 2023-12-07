#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "helpers.h"

// Altera a ordem dos caracteres
void reverse_string(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

bool is_zero_string(const char *string, int length) {
    return length == 1 && string[0] == '0';
}

char *remove_leading_zeroes(char *str, int len, int *new_len) {
    int start = 0;
    while (str[start] == '0' && start < len - 1) {
        start++;
    }

    *new_len = len - start;
    char *final_result = calloc((*new_len + 1), sizeof(char));
    
    for (int i = 0; i < *new_len; i++) {
        final_result[i] = str[start + i];
    }

    return final_result;
}