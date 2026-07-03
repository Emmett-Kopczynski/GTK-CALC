#ifndef GRAPHICALUTILS_H_
#define GRAPHICALUTILS_H_

/* inclusions */
#include <gtk/gtk.h>

/* Symbolic constants */
#define BUTTONSIZE 90

/* run : builds, runs, and frees the gtk app ran with start
 * 
 * Arguments
 *    - argc : type int : the number of command line arguments
 *    - argv : type char * [] : the command line arguments
 *
 * RETURNS : a 0 if everything went well, a different number otherwise
 */
int run(int argc, char *argv[]);


/* run_button : code ran when a button is pressed, calls the signal handler with the button label info
 * 
 * Arguments
 *    - button : type GtkWidget * : the button being activated
 *    - data : type gpointer : the data being passed to the function, in this case a GtkTextView AKA the textbox
 */
void run_button(GtkWidget *button, gpointer data);

/* set_text_box : sets the given text view with the given string
 * 
 * Arguments
 *    - textbox : type GtkTextView * : the textbox being updated with new text
 *    - text : type char * : the text being placed in the textbox
 */
void set_text_box(GtkTextView *textbox, char *text);

/* start : runs the app from run, builds all the GUI elements for the application
 *
 * Arguments
 *    - app : GtkApplication * : the application we are running
 *    - user_data : type gpointer : the data part of a g_signal function, unused here
 */
void start(GtkApplication *app, gpointer user_data);

#endif
