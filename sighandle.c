/* sighandle : handlses the signals from the buttons
 *
 * Author : Emmett James Kopczynski
 * 
 * To Do :
 *
 * Known Bugs :
 */

/* inclusions */
#include "sighandle.h"
#include "graphicutils.h"
#include "calculator.h"
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

/* External variables */
const char *signals[NUMBEROFSIGNALS] = { "1\0", "2\0", "3\0", "+\0",
                                 "4\0", "5\0", "6\0", "-\0", 
                                 "7\0", "8\0", "9\0", "/\0",
                                 "0\0", "(\0", ")\0", "*\0", 
                                  "DEL\0", "^\0", ".\0", "=\0"};
;

/* interperet_signal : interperets signals sent from buttons to do various actions, kind of the controll center of the whole ass application */
void interperet_signal(char signal[], GtkTextView *textbox){
    if( signal[0] == '=' ){   
        char answer[MAXEQUATIONLEN];
        solve_external_equation(answer);
        set_text_box( GTK_TEXT_VIEW( textbox ), answer);
        delete_external_equation();
    }else if(strlen(signal) < 2){
        concat_external_equation(signal[0]);
        set_text_box( GTK_TEXT_VIEW( textbox ), infix_equation);
    } else {
        delete_last_external_equation();
        set_text_box( GTK_TEXT_VIEW( textbox ), infix_equation);
    }
}



