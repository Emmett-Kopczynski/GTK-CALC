/* calculator : conatins all equation methods, both for editing the external
 * infix expression and for solving infix expressions in general
 *
 * Author: Emmett James Kopczynski
 *
 * TO DO:
 *
 *  TO IMPLEMENT :
 *      - par_mult
 *  TO DOCUMENT :
 *     - par_mult
 *
 * Known Bugs :
 *   - Starting with a negative number causes a single stack overflow error
 *   - .^. always gives an answer of 1, which is obviously false, this should give an error screen, try to solve this for more than just that case
 *   - 8(7 + 8) causes an error, make function to change it to 8*(7 + 8)
 */

/* inclusions */
#include "calculator.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* external expressions */
char infix_equation[MAXEQUATIONLEN] = "";

/* concat_external_equation : adds the given character to the end of the external infix_equation */
void concat_external_equation(char addition){
    int len = strlen(infix_equation);
    if(len < MAXEQUATIONLEN - 2){ /* minus two to make room for the addition and the new \0 */
        infix_equation[len] = addition;
        infix_equation[len + 1] = '\0';
    }
}

/* delete_last_external_equation : removes the character at the end of the equation */
void delete_last_external_equation(){
    int len = strlen(infix_equation);
    if(len > 0){
        infix_equation[len - 1] = '\0';
    }
}

/* delete_external_equation : clears the text in the external infix equation */
void delete_external_equation(){
    infix_equation[0] = '\0';
}

/* solve_external_equation : solves the external equation and places the answer into the given string */
void solve_external_equation(char *answer){

    /* TODO add syntax checking for the equation */
    if( check_paranthesis(infix_equation) < 0){ /* paranthasis checking */
        answer[0] = '\0';
        strcpy(answer, "PARANTHESIS ERROR");
        return;
    }
    if(zero_div_check(infix_equation) < 0){ /* divide by zero checking */
        answer[0] = '\0';
        strcpy(answer, "CANNOT DIVIDE BY ZERO");
        return;
    }
    /* TODO add a thing that makes 8(8+2) into 8*(8+2) if that makes sense */

    char postfix[MAXEQUATIONLEN * 2];
    to_postfix_expression(infix_equation, postfix);
    double ansNum = solve_postfix_expression( postfix ) ;
    sprintf(answer, "%f", ansNum);
}

/* zero_div_check : returns zero if infix does not divide by zero, otherwise returns -1 */
int zero_div_check(char *infix){
    char prev_term[MAXEQUATIONLEN] = "\0";
    char cur_term[MAXEQUATIONLEN] = "\0";
    int index = 0;
    while(index < strlen(infix)){
        index = parse_term(infix, index, cur_term);
        if(prev_term[0] == '/' && atof(cur_term) == 0){
            return -1;
        }

        strcpy(prev_term, cur_term);
    }

    return 0;
}

/* TODO document */
int par_mult(char *infix){ /* edits the infix_equaton to have paranthesis mult,
   ex 8(8+9) turn to 8*(8+9) */
    return -1; /* return the amount of * added */
} /* TODO implement */

/* check_paranthesis : checks that parenthesis are legal, returns 0 if good, otherwise -1 */
int check_paranthesis(char *infix){
    Stack open_par = construct_stack_new();
    int i; i = 0;
    for(i = 0; i < strlen(infix); i ++){
        if(infix[i] == '('){
            open_par.push(&open_par, "(");
        }
        if ( infix[i] == ')'){
            if(open_par.isEmpty(&open_par)){
               return -1;
            } else{
                open_par.pop(&open_par);
            }
        }
    }

    if(open_par.isEmpty(&open_par) ){
        return 0; /* no error */
    } else{
        return -1; /* error */
    }

}

/* to_postfix_expression : takes an infix expression and creates a postfix expression given to the given 'postfix' string */
void to_postfix_expression(char infix[], char postfix[]){
    /* builds the stack */
    Stack myStack;
    myStack = construct_stack_new();
    /* for storing the terms */
    char tmp[MAXEQUATIONLEN];
    /* makes sure postfix is prepped */
    postfix[0] = '\0';

    int index = 0;

    while(index < strlen(infix)){
        index = parse_term(infix, index, tmp);

        if(!is_operator(tmp[0])){ /* operand and () branch */
            if(tmp[0] == '('){ /* ( branch */
                myStack.push(&myStack, "(");
            } else if(tmp[0] == ')'){ /* ) branch */
                while( strcmp(myStack.peek(&myStack), "(") != 0){ /* goes until "(" is on top of the stack */
                    strcat(postfix, myStack.pop(&myStack));
                    strcat(postfix, ",");
                }
                myStack.pop(&myStack); /* pops the "(" which is on top of the stack*/
            } else { /* operand branch */
                strcat(postfix, tmp);
                strcat(postfix, ",");
            }
        } else{ /* operator +, -, ^, *, / branch */
            while(!myStack.isEmpty(&myStack)){
                if(precedence_on_stack(myStack.peek(&myStack)[0]) > precedence_off_stack(tmp[0]))
                {
                    strcat(postfix, myStack.pop(&myStack));
                    strcat(postfix, ",");
                } else{
                    break;
                }
            }
            myStack.push(&myStack,tmp);
        }
    }

    while(!myStack.isEmpty(&myStack)){
        strcat(postfix, myStack.pop(&myStack));
        strcat(postfix, ",");
    }

    postfix[strlen(postfix) - 1] = '\0'; /* takes off the last , from the postfix equation */

}

/* solve_postfix_expression : solves the given postfix equation and returns the answer as a double */
double solve_postfix_expression(char postfix[]){
    Stack myStack;
    myStack = construct_stack_new();

    int index = 0;
    char tmp[MAXEQUATIONLEN * 2];
    char answertmp[MAXEQUATIONLEN * 2];

    while(index < strlen(postfix)){
        index = parse_postfix_term(postfix, index, tmp); /* updates tmp */

        if(!is_operator(tmp[0])){ /* operand branch */
            myStack.push(&myStack, tmp);
        }  else{ /* operator branch */
            double right = atof(myStack.pop(&myStack));
            double left = atof(myStack.pop(&myStack));
            switch(tmp[0]){
                case '+':
                    sprintf(answertmp, "%f", (left + right) );
                    myStack.push(&myStack, answertmp);
                    break;
                case '-':
                    sprintf(answertmp, "%f", (left - right) );
                    myStack.push(&myStack, answertmp);
                    break;

                case '*':
                    sprintf(answertmp, "%f", (left * right) );
                    myStack.push(&myStack, answertmp);
                    break;

                case '/':
                    sprintf(answertmp, "%f", (left / right) );
                    myStack.push(&myStack, answertmp);
                    break;

                case '^':
                    sprintf(answertmp, "%f", (pow(left, right)) );
                    myStack.push(&myStack, answertmp);
                    break;

                default:
                    fprintf(stderr, "ERROR IN SOLVING POSTFIX\n");
            }
        }
    }

    if(myStack.getSize(&myStack) == 1)
        return atof(myStack.pop(&myStack));
    else
        return -1.0;
}

/* precedence_on_stack : returns the on stack precedence of a given operator in postfix operations*/
int precedence_on_stack(char operator){
    switch(operator){
        case '(':
            return 0;
        case '^':
            return 5;
        case '*':
        case '/':
            return 4;
        case '+':
        case '-':
            return 2;
        default:
            return -1;
    }
}

/* precedence_off_stack : returns the off stack precedence of a given operator in postfix operations */
int precedence_off_stack(char operator){
    switch(operator){
        case '(':
            return 100;
        case ')':
            return 0;
        case '^':
            return 6;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

/* parse_term : parses the next "term" in the equation, either a number or an operator */
int parse_term(char *eq, int start_index, char *term){
    /* puts the next terms from eq into the term variable */
    /* returns the new starting index */

    /* NOTE, operators are terms, numbers are terms, and ( or ) are also both terms */
    if ( is_operator(eq[start_index]) || eq[start_index] == '(' || eq[start_index] == ')'){
        /* for operators and parenthasis */
        term[0] = eq[start_index];
        term[1] = '\0';
        return start_index + 1;
    } else{
        /* for numbers */
        int new_index = start_index;
        int i = 0;
        while( !is_operator(eq[new_index]) && eq[new_index] != '\0' && eq[new_index] != '(' && eq[new_index] != ')'){ /* goes till operator */
            term[i] = eq[new_index];
            i += 1;
            new_index += 1;
        }
        term[i] = '\0';
        return new_index;
    }

}

/* parse_postfix_term : parses the next "term" in the postfix equation, either a number or an operator */
int parse_postfix_term(char *eq, int start_index, char *term){
    int new_index = start_index;
    int i = 0;

    while(eq[new_index] != '\0' && eq[new_index] != ','){
        term[i] = eq[new_index];

        i += 1; new_index += 1;
    }

    term[i] = '\0';

    return new_index + 1; /* +1 to skip over the , character */
}

/* is_operator : returns 1 if char is an operator, and 0 if it is not */
int is_operator(char possible_operator){
    switch (possible_operator){
        case '*':
        case '/':
        case '^':
        case '+':
        case '-':
            return 1;
            break;

        default:
            return 0;
    }
}
