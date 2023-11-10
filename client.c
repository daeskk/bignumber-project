#include <stdio.h>
#include <stdlib.h>

#include "expression.h"
#include "custom_io.h"

int main() {
    while(1) {
        struct expression *expression = create_expression();

        PRINT_EXPRESSION(expression);

        destroy_expression(expression);
    }
}