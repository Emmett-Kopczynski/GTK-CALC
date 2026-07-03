/*  CalcTest.c :: this program is for testing the
 * helper funcions in calculator.c
 *
 * TODO ::
 *
 *  To Implement :
 *      - precedence_off_stack_TEST
 *      - parse_term_TEST3
 *      - to_postfix_expression_TEST1
 *      - to_postfix_expression_TEST2
 *      - to_postfix_expression_TEST3
 *      - solve_postfix_expression_TEST1
 *      - solve_postfix_expression_TEST2
 *      - solve_postfix_expression_TEST3
 *  To Document :
 *      - precedence_off_stack_TEST
 *      - parse_term_TEST3
 *      - to_postfix_expression_TEST1
 *      - to_postfix_expression_TEST2
 *      - to_postfix_expression_TEST3
 *      - solve_postfix_expression_TEST1
 *      - solve_postfix_expression_TEST2
 *      - solve_postfix_expression_TEST3
 *
 * Known Bugs :
 *
 *
 *  NOTES ::
 *
 */


/* inclusion statements */
#include "calculator.h"
#include <stdio.h>
#include <string.h>

/* function prototypes */
void runTests();
void precedence_on_stack_TEST(int pass_fail[]);
void precedence_off_stack_TEST(int pass_fail[]);
void parse_term_TEST1(int pass_fail[]);
void parse_term_TEST2(int pass_fail[]);
void parse_term_TEST3(int pass_fail[]);
void is_operator_TEST(int pass_fail[]);
void to_postfix_expression_TEST1(int pass_fail[]);
void to_postfix_expression_TEST2(int pass_fail[]);
void to_postfix_expression_TEST3(int pass_fail[]);
void solve_postfix_expression_TEST1(int pass_fail[]);
void solve_postfix_expression_TEST2(int pass_fail[]);
void solve_postfix_expression_TEST3(int pass_fail[]);


int main(int argc, char *argv[]){
    runTests();
    return 0;
}


/* runTests : runs all the CalcTest tests and displays the results */
void runTests(){

    int pass_fail[2] = {0, 0};

    /* start message */
    printf("\n\nCalcTest Tests :: Start\n");


    precedence_on_stack_TEST(pass_fail);
    /*
    precedence_off_stack_TEST(pass_fail);
    */

    parse_term_TEST1(pass_fail);
    parse_term_TEST2(pass_fail);
    parse_term_TEST3(pass_fail);

    is_operator_TEST(pass_fail);

    to_postfix_expression_TEST1(pass_fail);
    to_postfix_expression_TEST2(pass_fail);
    /*
    to_postfix_expression_TEST3(pass_fail);

    solve_postfix_expression_TEST1(pass_fail);
    solve_postfix_expression_TEST2(pass_fail);
    solve_postfix_expression_TEST3(pass_fail);
    */

    printf("\n\nSUMMARRY\n");
    if(pass_fail[1] == 0){
        printf("\tAll %d Tests Passed\n", pass_fail[0]);
    } else{
        printf("\tTests Passed :: %d\n", pass_fail[0]);
        printf("\tTests Failed :: %d\n", pass_fail[1]);
    }
    printf("\n\n");

} /* TODO implement */

/* precedence_on_stack_TEST :: tests the precedence_on_stack function */
void precedence_on_stack_TEST(int pass_fail[]){
    /* Assign */
    char openpar = '(';
    char expon = '^';
    char mult = '*';
    char div = '/';
    char plus = '+';
    char minus = '-';
    char other = '8';
    int trueifpassed = 1;
    /* Act */
    trueifpassed &= (precedence_on_stack(openpar) == 0);
    trueifpassed &= (precedence_on_stack(expon) == 5);
    trueifpassed &= (precedence_on_stack(mult) == 4);
    trueifpassed &= (precedence_on_stack(div) == 4);
    trueifpassed &= (precedence_on_stack(plus) == 2);
    trueifpassed &= (precedence_on_stack(minus) == 2);
    trueifpassed &= (precedence_on_stack(other) == -1);

    /* Assert */
    if(trueifpassed){
        printf("\tprecedence_on_stack_TEST :: PASSED\n");
        pass_fail[0] += 1;
    } else{
        printf("\tprecedence_on_stack_TEST :: FAILED\n");
        pass_fail[1] += 1;
    }
}

/* TODO document */
void precedence_off_stack_TEST(int pass_fail[]){
    return;
} /* TODO implement */

/* parse_term_TEST1 :: tests the parse_term function for starting numbers */
void parse_term_TEST1(int pass_fail[]){
    /* Assign */
    char *term = "856.2*7";
    int sindex = 0;
    int exindex = 0; /* finishes as 5 */
    char exterm[100]; /* finishes as 856.2 */
    /* Act */
    exindex = parse_term(term, sindex, exterm);

    /* Assert */
    if(strcmp(exterm, "856.2") == 0 && exindex == 5){
        printf("\tparse_term_TEST1 :: PASSED\n");
        pass_fail[0] += 1;
    } else{
        printf("\tparse_term_TEST1 :: FAILED\n");
        pass_fail[1] += 1;
    }
}

/* parse_term_TEST2 :: tests chaining the parse_terms function twice,
 * once grabbing an operator, once grabbing a number*/
void parse_term_TEST2(int pass_fail[]){
    /* Assign */
    char *eqterm = "875.909+78.3\0";
    int eqindex = 7;
    int secondindex = 0; /* should end as 8 */
    int endindex = 0; /* should end as 12, AKA strlen(eqterm) */
    char exoperator[100]; /* should end as + */
    char exnumber[100]; /* should end as 78.3 */

    /* Act */
    secondindex = parse_term(eqterm, eqindex, exoperator);
    endindex = parse_term(eqterm, secondindex, exnumber);

    /* Assert */
    if(
        strcmp(exoperator, "+\0") == 0 &&
        strcmp(exnumber, "78.3\0") == 0 &&
        secondindex == 8 &&
        endindex == strlen(eqterm))
    {
        printf("\tparse_term_TEST2 :: PASSED\n");
        pass_fail[0] += 1;
    } else{
        printf("\tparse_term_TEST2 :: FAILED\n");
        pass_fail[1] += 1;
    }
}

/* parse_term_TEST3 :: tests making a new string using repeated use of the parse_term function */
void parse_term_TEST3(int pass_fail[]){
    /* Assign */
    char *eqterm = "(78*5.2)\0";
    char tmp[100];
    char exterm[100] = "\0"; /* should end as "(,78,*,5.2,)" */
    int index = 0;

    /* Act */
    while(index < strlen(eqterm)){
        index = parse_term(eqterm, index, tmp);
        strcat(exterm, tmp);
        if(index != strlen(eqterm)){
            strcat(exterm, ",");
        }
    }
    /* Assert */
    if(strcmp(exterm, "(,78,*,5.2,)") == 0 &&
        index == strlen(eqterm) )
    {
        printf("\tparse_term_TEST3 :: PASSED\n");
        pass_fail[0] += 1;
    }else{
        printf("\tparse_term_TEST3 :: FAILED\n");
        pass_fail[1] += 1;
    }
}

/* is_operator_TEST :: tests the is_operator function*/
void is_operator_TEST(int pass_fail[]){
    /* Assign */
    char plus = '+';
    char minus = '-';
    char divide = '/';
    char multiply = '*';
    char exponent = '^';
    char notop1 = '3';
    char notop2 = '7';
    char notop3 = '.';
    int trueifpass = 1;

    /* Act  + Assert*/
    trueifpass &= is_operator(plus);
    trueifpass &= is_operator(minus);
    trueifpass &= is_operator(divide);
    trueifpass &= is_operator(multiply);
    trueifpass &= is_operator(exponent);
    trueifpass &= !is_operator(notop1);
    trueifpass &= !is_operator(notop2);
    trueifpass &= !is_operator(notop3);

    /* Print Results */

    if(trueifpass){
        printf("\tis_operator_TEST :: PASSED\n");
        pass_fail[0] += 1;
    } else{
        printf("\tis_operator_TEST :: FAILED\n");
        pass_fail[1] += 1;
    }
}

/* to_postfix_expression_TEST1 :: tests to_postfix_expression for 8+4*2 */
void to_postfix_expression_TEST1(int pass_fail[]){
    /* Assign */
    char *infix = "8+4*2";
    char *expectedPostfix = "8,4,2,*,+";
    char postfix[100];

    /* Act */

    to_postfix_expression(infix, postfix);

    /* Assert */
    if(strcmp(postfix, expectedPostfix) == 0){
        printf("\tto_postfix_expression_TEST1 :: PASSED\n");
        pass_fail[0] += 1;
    } else{
        printf("\tto_postfix_expression_TEST1 :: FAILED\n");
        pass_fail[1] += 1;
    }

}

/* to_postfix_expression_TEST2 :: tests to_postfix_expression for (((1+2_-(3-4))/((6-5))*/
void to_postfix_expression_TEST2(int pass_fail[]){
    /* Assign */
    char *infix = "(((1+2)-(3-4))/(6-5))";
    char *expectedPostfix = "1,2,+,3,4,-,-,6,5,-,/";
    char postfix[100];

    /* Act */

    to_postfix_expression(infix, postfix);

    /* Assert */
    if(strcmp(postfix, expectedPostfix) == 0){
        printf("\tto_postfix_expression_TEST2 :: PASSED\n");
        pass_fail[0] += 1;
    } else{
        printf("\tto_postfix_expression_TEST2 :: FAILED\n");
        pass_fail[1] += 1;
    }
}

/* TODO document */
void to_postfix_expression_TEST3(int pass_fail[]){
    return;
} /* TODO implement */

/* TODO document */
void solve_postfix_expression_TEST1(int pass_fail[]){
    return;
} /* TODO implement */

/* TODO document */
void solve_postfix_expression_TEST2(int pass_fail[]){
    return;
} /* TODO implement */

/* TODO document */
void solve_postfix_expression_TEST3(int pass_fail[]){
    return;
} /* TODO implement */
