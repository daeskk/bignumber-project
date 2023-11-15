#ifndef __PROCESS_H__
#define __PROCESS_H__

#include <stdio.h>
#include "expression.h"

// Definições dos processos que serão realizados
struct process {
    struct expression **expressions;
    int size;
    int capacity;
};

struct process *create_process();

void add_process(struct process *process, struct expression *expression);
void print_process(struct process *process);
void destroy_process(struct process *process);

#endif