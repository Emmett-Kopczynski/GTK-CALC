
#include <stdio.h>
#include <string.h>
#include "stack.h"

/* Function headers */
void stackTest( int *fail_success);

void peekTestOne( int *fail_success);
void peekTestTwo( int *fail_success);
void peekTestThree(int *fail_success);

void popTestOne(int *fail_success);
void popTestTwo(int *fail_success);
void popTestThree(int *fail_success);

void pushTestOne(int *fail_success);
void pushTestTwo(int *fail_success);
void pushTestThree(int *fail_success);

void isEmptyTestOne(int *fail_success);
void isEmptyTestTwo(int *fail_success);
void isEmptyTestThree(int *fail_success);

void getSizeTestOne(int *fail_success);
void getSizeTestTwo(int *fail_success);
void getSizeTestThree(int *fail_success);


int main(int argc, char *argv[]){
    int fail_success[2];
    fail_success[0] = fail_success[1] = 0;
    stackTest(fail_success);
    
    printf("\n\nSummary\n");
    printf("\tTotal Tests :: %d\n", fail_success[0] + fail_success[1]);
    printf("\tTests Failed :: %d\n", fail_success[0]);
    printf("\tTests Passed :: %d\n", fail_success[1]);

    return 0;
}

void stackTest( int *fail_success){
    printf("Stack Tests\n");
    
    peekTestOne( fail_success);
    peekTestTwo( fail_success);
    peekTestThree( fail_success);
    
    /*   
    popTestOne(fail_success);
    popTestTwo(fail_success);
    popTestThree(fail_success);

    pushTestOne(fail_success);
    pushTestTwo(fail_success);
    pushTestThree(fail_success);
    */
    isEmptyTestOne(fail_success);
    isEmptyTestTwo(fail_success);
    isEmptyTestThree(fail_success);

    /*
    getSizeTestOne(fail_success);
    getSizeTestTwo(fail_success);
    getSizeTestThree(fail_success);
    */
}

void peekTestOne(int *fail_success){
    Stack myStack;
    myStack = construct_stack_new();

    myStack.push(&myStack, "Hello World\0");
    if(myStack.getSize(&myStack) == 1 && strcmp(myStack.peek(&myStack), "Hello World\0") == 0){
        fail_success[1] += 1;
        printf("\tpeekTestOne :: Passed\n");
    } else{
        fail_success[0] += 1;
        printf("\tpeekTestOne :: Failed\n");
    }
}

void peekTestTwo(int *fail_success){
    Stack myStack;
    myStack = construct_stack_new();

    if(myStack.getSize(&myStack) == 0 && strcmp(myStack.peek(&myStack), "Stack Underflow Error\0") == 0){
        fail_success[1] += 1;
        printf("\tpeekTestTwo :: Passed\n");
    } else {
        fail_success[0] += 1;
        printf("\tpeekTestTwo :: Failed\n");
    }
}

void peekTestThree(int *fail_success){
    Stack myStack;
    myStack = construct_stack_new();

    myStack.push(&myStack, "Hello World1\0");
    myStack.push(&myStack, "Hello World2\0");
    myStack.push(&myStack, "Hello World3\0");
    
    myStack.pop(&myStack);
    myStack.pop(&myStack);

    myStack.push(&myStack, "HelloWorld4\0");

    if(myStack.getSize(&myStack) == 2 && strcmp(myStack.peek(&myStack), "HelloWorld4\0") == 0  ){
        printf("\tpeekTestThree :: Passed\n");
        fail_success[1] += 1;
    } else{
        printf("\tpeekTestThree :: Failed\n");
        fail_success[0] += 1;
    }

}

void isEmptyTestOne(int *fail_success){
    Stack myStack;
    myStack = construct_stack_new();

    if(myStack.isEmpty(&myStack)){
        fail_success[1] += 1;
        printf("\tisEmptyTestOne :: Passed\n");
    } else{
        printf("\tisEmptyTestOne :: Failed\n");
        fail_success[0] += 1;
    }
}

void isEmptyTestTwo(int *fail_success){
    Stack myStack;
    myStack = construct_stack_new();
    
    myStack.push(&myStack, "HELLLO WORLD\0");

    if(!myStack.isEmpty(&myStack)){
        fail_success[1] += 1;
        printf("\tisEmptyTestTwo :: Passed\n");
    } else{
        printf("\tisEmptyTestTwo :: Failed\n");
        fail_success[0] += 1;
    }
}


void isEmptyTestThree(int *fail_success){
    Stack myStack;
    myStack = construct_stack_new();
    
    myStack.push(&myStack, "HELLOWORLD1");
    myStack.push(&myStack, "HELLOWORLD2");

    myStack.pop(&myStack);
    myStack.pop(&myStack);

    if(myStack.isEmpty(&myStack)){
        fail_success[1] += 1;
        printf("\tisEmptyTestThree :: Passed\n");
    } else{
        printf("\tisEmptyTestThree :: Failed\n");
        fail_success[0] += 1;
    }
}

