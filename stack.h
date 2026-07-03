#ifndef STACK_H_
#define STACK_H_

/* inclusions */
#include "calculator.h"

/* Stack : a basic stack data structure for storing strings */
typedef struct stack{
    int size;
    char arrayStack[MAXEQUATIONLEN][MAXEQUATIONLEN]; /* the top is arrayStack[size - 1] */

    /* TODO document */
    char * (*peek)(struct stack *stack); 
    
    /* TODO document */
    char * (*pop)(struct stack *stack);
    
    /* TODO document */
    void (*push)(struct stack *stack, char toAdd[]);
    
    /* TODO document */
    int (*isEmpty)(struct stack *stack);
    
    /* TODO document */
    int (*getSize)(struct stack *stack);
} Stack;

/* construct_stack_new : constructor method for the stack */
Stack construct_stack_new();

/* peek_stack :  */
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
