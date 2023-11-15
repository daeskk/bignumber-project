#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "process.h"

// Cria um novo processo com memória dinâmica
struct process *create_process() {
    struct process *new_process = malloc(sizeof(struct process));
    
    new_process->expressions = NULL;
    new_process->capacity = 0;
    new_process->size = 0;


    return new_process;
}

// Incrementa as expressões a serem realizadas
void add_process(struct process *process, struct expression *expression) {
    assert(process != NULL && expression != NULL);

    if (process->size == process->capacity) {
        int old_capacity = process->capacity;
        process->capacity = process->capacity == 0 ? 2 : process->capacity * 2;

        process->expressions = realloc(process->expressions, process->capacity * sizeof(struct expression *));
    }

    process->expressions[process->size++] = expression;
}

// Libera a memória utilizada
void destroy_process(struct process *process) {
    assert(process != NULL);

    for (int i = 0; i < process->size; i++) {
        destroy_expression(process->expressions[i]);
    }

    free(process->expressions);
    free(process);
}

// Att: falta coisa aqui?
void print_process(struct process *process) {
    assert(process != NULL);
}