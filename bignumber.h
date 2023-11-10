#ifndef __BIGNUMBER_H__
#define __BIGNUMBER_H__

#include <stdbool.h>

struct big_number {
    char *digits;
    size_t length;
    bool negative;
};

struct big_number *read_big_number();

char *add_big_numbers(char *num1, char *num2);

void destroy_big_number(struct big_number *number);

#define PRINT_BIG_NUMBER(bn) do { \
    if ((bn) != NULL) { \
        if ((bn)->negative) { \
            printf("-"); \
        } \
        printf("%s\n", (bn)->digits); \
    } else { \
        printf("Null big_number\n"); \
    } \
} while (0)

#endif