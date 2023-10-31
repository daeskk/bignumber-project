#include <stdio.h>
#include <stdlib.h>

#include "bignumber.h"
#include "custom_io.h"

int main() {
    while(1) {
        struct big_number *bg1 = read_big_number();
        struct big_number *bg2 = read_big_number();
        char op = getchar();

        PRINT_BIG_NUMBER(bg1);
        PRINT_BIG_NUMBER(bg2);
        printf("operation: %c\n", op);

        destroy_big_number(bg1);
        destroy_big_number(bg2);
    }
}