#ifndef STACK_H_
#define STACK_H_

/* inclusions */
#include "calculator.h"

/* TODO document stack */
typedef struct stack{
    int size;
    char arrayStack[MAXEQUATIONLEN][MAXEQUATIONLEN]; /* the top is arrayStack[size - 1] */

    char * (*peek)(struct stack *stack);
    char * (*pop)(struct stack *stack);
    void (*push)(struct stack *stack, char toAdd[]);
    int (*isEmpty)(struct stack *stack);
    int (*getSize)(struct stack *stack);
} Stack;

/* TODO document construct_stack_new */
Stack construct_stack_new();

/* TODO document peek_stack */
char * peek_stack(Stack *stack);

/* TODO document pop_stack */
char * pop_stack(Stack *stack);

/* TODO document push_stack */
void push_stack(Stack *stack, char toAdd[]);

/* TODO document isEmpty_stack */
int isEmpty_stack(Stack *stack);

/* TODO document size_stack */
int getSize_stack(Stack *stack);


#endif
