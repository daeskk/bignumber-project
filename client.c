// Código final utilizado para run do projeto - para rodar: ./client no terminal
#include <stdio.h>
#include <stdlib.h>

#include "process.h"

int main() {
    struct process *process = create_process();
    
    while(1) {
        struct expression *expression = create_expression();
        add_process(process, expression);
        calculate_expression(expression);   

        char next_char = getchar();
        
        if (next_char == EOF || next_char == '\n') break;

        ungetc(next_char, stdin);
    }

    print_process(process);

    destroy_process(process);
}