#ifndef CALCULATOR_H_
#define CALCULATOR_H_

/* symbolic constants */
#define MAXEQUATIONLEN 200 /* MAXEQUATIONLEN : the maximum length of external equation */

/* infix_equation : the equation in the calculator to be solved */
extern char infix_equation[MAXEQUATIONLEN];

/* concat_external_equation : add the given character to the external equation
 *
 * Arguments :
 *     - addition : type char : the character being put at the end of the equation
 */
void concat_external_equation(char addition);

/*  delete_last_external_equation : removes last character from the external equation */
void delete_last_external_equation();

/* delete_external_equation :  makes the external equation blank */
void delete_external_equation();

/* solve_external_equation : solves the external equation
 *
 * NOTE : utilizes to_postfix_expression and solve_postfix_expression
 *
 * Arguments :
 *     - answer : char * : the place we want the answer written to
 *
 * NOTE : the equation being solved comes from the external
 * variable string infix_equation
 */
void solve_external_equation(char *answer);

/* TODO document check_paranthesis */
int check_paranthesis(char *infix);

/* TODO document zero_div_check */
int zero_div_check(char *infix);

/* TODO document par_mult */
int par_mult(char *infix);

/*  to_postfix_expression : turns the given infix expression into a postfix expression
 *
 * Arguments :
 *     - infix : type char [] : the infix equaton being changed to a postfix one
 *     - postfix : type char [] : where we want the postfix equation written to
 */
void to_postfix_expression(char infix[], char postfix[]);

/*  solve_postfix_expression : solves the postfix expression
 *
 * Arguments :
 *     - postfix : type char [] : the postfix equation we are going to solve
 *
 * RETURNS : the answer to the equation
 */
double solve_postfix_expression(char postfix[]);

/* precedence_on_stack : returns the precedence for the given operator on the stack
 *
 * Arguments :
 *     - operator : type char : the operator we are getting the precedence of
 *
 * RETURNS : the precedence as an integer
 */
int precedence_on_stack(char operator);

/* precedence_off_stack : returns the precedence for the given operator off the stack
 *
 * Arguments :
 *     - operator : type char : the operator we are getting the precedence of
 *
 * RETURNS : the precedence as an integer
 */
int precedence_off_stack(char operator);

/* parse_term : parses a term in an infix equation
 *
 * Arguments :
 *    - eq : type char * : the infix equation
 *    - start_index : type int : where we start when parsing eq
 *    - term : type char * : where we write the found term to
 *
 * RETURNS : the ending index of the term + 1
 */
int parse_term(char *eq, int start_index, char *term);

/* parse_postfix_term : parses a term in a postfix equation
 *
 * Arguments :
 *    - eq : type char * : the postfix equation
 *    - start_index : type int : where we start when parsing eq
 *    - term : type char * : where we write the found term to
 *
 * RETURNS : the ending index of the term + 1
 */
int parse_postfix_term(char *eq, int start_index, char *term);

/* is_operator : indicates whether given char is an operator
 *
 * Arguments :
 *     - possible_operator : type char : the char we are checking
 *
 * RETURNS : returns 1 (true) if it is an operator, and 0 (false) if it is not
 */
int is_operator(char possible_operator);

#endif
