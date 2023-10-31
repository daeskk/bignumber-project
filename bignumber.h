#ifndef __BIGNUMBER_H__
#define __BIGNUMBER_H__

enum operation {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
};

struct big_number {
    char *digits;
    int length;
};

struct calculation {
    enum operation operation;
    struct big_number numbers[2];
};

struct big_number *create_big_number(char *digits);
void destroy_big_number(struct big_number *number);

static inline enum operation convert_operation(char op) {
    switch (op) {
        case '+':
            return ADDITION;
        case '-':
            return SUBTRACTION;
        case '*':
            return MULTIPLICATION;
    }
}

#endif