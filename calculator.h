#ifndef CALCULATOR_H_
#define CALCULATOR_H_

/* symbolic constants */
#define MAXEQUATIONLEN 200 /* TODO document */

/* TODO document infix_equation */
extern char infix_equation[MAXEQUATIONLEN];

/* concat_external_equation : add the given character to the external equation
 * TODO document concat_external_equation
 */
void concat_external_equation(char addition);

/*  delete_last_external_equation : removes last character from the external equation
 */
void delete_last_external_equation();

/* delete_external_equation :  makes the external equation blank
 */
void delete_external_equation();

/* solve_external_equation : solves the external equation
 * NOTE : utilizes to_postfix_expression and solve_postfix_expression
 * TODO finish noting later
 */
void solve_external_equation(char *answer);

/* TODO document check_paranthesis */
int check_paranthesis(char *infix);

/* TODO document zero_div_check */
int zero_div_check(char *infix);

/* TODo document par_mult */
int par_mult(char *infix);

/*  to_postfix_expression : turns the given infix expression into a postfix expression
 * TODO document to_postfix_expression
 */
void to_postfix_expression(char infix[], char postfix[]);

/*  solve_postfix_expression : solves the postfix expression
 * TODO document solve_postfix_expression
 */
double solve_postfix_expression(char postfix[]);

/* TODO document precedence_on_stack */
int precedence_on_stack(char operator);

/* TODO document precedence_off_stack */
int precedence_off_stack(char operator);

/* TODO document parse_term */
int parse_term(char *eq, int start_index, char *term);

/* TODO document parse_postfix_term */
int parse_postfix_term(char *eq, int start_index, char *term);

/* TODO document is_operand */
int is_operator(char possible_operator);

#endif
