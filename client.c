#include <stdio.h>
#include <stdlib.h>

#include "expression.h"
#include "custom_io.h"

#define DEBUG 1

int main() {
    while(1) {
        struct expression *expression = create_expression();



        calculate(expression);
        
        #if DEBUG
            PRINT_EXPRESSION(expression);
        #endif

        destroy_expression(expression);
    }
}