#include <stdio.h>
#include <stdlib.h>

#include "bignumber.h"
#include "custom_io.h"

int main() {
    while(1) {
        char *tst = read_input();
        struct big_number *tst2 = create_big_number(tst);

        printf("Number: %s\n", tst2->digits);

        destroy_big_number(tst2);
    }
}