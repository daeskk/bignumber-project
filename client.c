// Código final utilizado para run do projeto - para rodar: ./client no terminal
#include <stdio.h>
#include <stdlib.h>

#include "process.h"
#include "expression.h"

#define DEBUG 1

int main() {
    struct process *process = create_process();
    
    while(1) {
        struct expression *expression = create_expression();
        add_process(process, expression);
        calculate_expression(expression);
        
        #if DEBUG
            printf("\n=======================\n");
            PRINT_EXPRESSION(expression);
            printf("======================\n");
        #endif
    }

    print_process(process);

    destroy_process(process);
}