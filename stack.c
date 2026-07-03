/* stack : contains the functions and definitions for the stack of character strings
 *
 * Author : Emmett James Kopczynski
 *
 * To Do :
 *     - Make Error Messages print to stderr
 *
 * Known Bugs : NONE
 */


/* inclusions */
#include "stack.h"
#include <stdio.h>
#include <string.h>

/* construct_stack_new : constructs a new stack with starting size of 0 */
Stack construct_stack_new(){
    Stack new_stack;
    new_stack.size = 0;

    new_stack.peek = &peek_stack;
    new_stack.pop = &pop_stack;
    new_stack.push = &push_stack;
    new_stack.isEmpty = &isEmpty_stack;
    new_stack.getSize = &getSize_stack;

    return new_stack;
}

/* peek_stack : looks at the top of a given stack, throws stack underflow if stack is empty */
char * peek_stack(Stack *stack){

    if( stack->size <= 0 ){ /* checks for stack underflow error (thrown if stack is empty) */
        printf("Stack Underflow Error\n");
        return "Stack Underflow Error\0";
    }
    return stack->arrayStack[stack->size - 1]; /* returns top */
}

/* pop_stack : returns the top of a given stack, and updates size and top */
char * pop_stack(Stack *stack){
    if( stack->size <= 0 ){ /* checks for stack underflow error (thrown if stack is empty) */
        printf("Stack Underflow Error\n");
        return "Stack Underflow Error\0";
    }
    char *returnable = stack->arrayStack[stack->size - 1]; /* gets top */
    stack->size -= 1; /* decreases size of the stack by 1 */

    return returnable;
}

/* push_stack : pushes a string onto the stack, asumes the given string has no \n or \0 at the end */
void push_stack(Stack *stack, char toAdd[]){
    if(strlen(toAdd) > MAXEQUATIONLEN){
        printf("STRING TO LONG FOR STACK\n");
        return;
    } else if(stack->size == MAXEQUATIONLEN){
        printf("STACK OVERFLOW ERROR\n");
        return;
    }
    strncpy(stack->arrayStack[stack->size] , toAdd, strlen(toAdd));
    stack->arrayStack[stack->size][strlen(toAdd)] = '\0';
    stack->size += 1;
}

/* isEmpty_stack : returns 1 (true) if stack is empty, otherwise returns 0 (false) */
int isEmpty_stack(Stack *stack){
    if(stack->size == 0)
        return 1; /* AKA true */
    else
        return 0; /* AKA false */
}

/* getSize_stack : returns the size of the stack */
int getSize_stack(Stack *stack){
    return stack->size;
}
