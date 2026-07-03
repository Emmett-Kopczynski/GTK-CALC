#ifndef STACK_H_
#define STACK_H_

/* inclusions */
#include "calculator.h"

/* Stack : a basic stack data structure for storing strings */
typedef struct stack{
    int size;
    char arrayStack[MAXEQUATIONLEN][MAXEQUATIONLEN]; /* the top is arrayStack[size - 1] */

    /* see peek_stack */
    char * (*peek)(struct stack *stack);

    /* see pop_stack */
    char * (*pop)(struct stack *stack);

    /* see push_stack */
    void (*push)(struct stack *stack, char toAdd[]);

    /* see isEmpty_stack */
    int (*isEmpty)(struct stack *stack);

    /* see getSize_stack */
    int (*getSize)(struct stack *stack);
} Stack;

/* construct_stack_new : constructs a new stack with a size of 0,
 * and puts the relevant functions from this file into the
 * functoin pointers of the same names
 */
Stack construct_stack_new();

/* peek_stack : looks at the top of a given stack
 *
 * Arguments :
 *     - stack : type Stack * : the stack you are peeking
 *
 * NOTE : if the stack is empty, it throws a Stack Underflow Error, returning
 * "Stack Underflow Error" as a string and printing it to stderr
 *
 * RETURNS : the top of the stack
 */
char * peek_stack(Stack *stack);

/* pop_stack : removes and returns the top of the stack
 *
 * Arguments :
 *     - stack : type Stack * : the stack you are poping
 *
 * NOTE : if the stack is empty, it throws a Stack Underflow Error, returning
 * "Stack Underflow Error" as a string and printing it to stderr
 *
 * RETURNS : the top of the stack that was just removed
 */
char * pop_stack(Stack *stack);

/* push_stack : pushes a string onto the stack
 *
 * Arguments :
 *     - stack : type Stack * : the stack you are pushing something onto
 *     - toAdd : type char [] : the string being pushed
 *
 * NOTE : assumes that given string has no \n or \0 at the end
 */
void push_stack(Stack *stack, char toAdd[]);

/* isEmpty_stack : indicates whether stack is empty or not
 *
 * Arguments :
 *     - stack : type Stack * : the stack you are checking
 *
 * RETURNS : returns a 1 (true) if the stack is empty, otherwise a 0 (false)
 */
int isEmpty_stack(Stack *stack);

/* getSize_stack : returns the size of the stack
 *
 * Arguments :
 *     - stack : type Stack * : the stack you are looking at
 *
 * RETURNS : returns the size of the stack as an integer
 */
int getSize_stack(Stack *stack);


#endif
