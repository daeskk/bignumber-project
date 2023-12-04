#ifndef __HELPERS_H__
#define __HELPERS_H__

#include <string.h>

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

#endif