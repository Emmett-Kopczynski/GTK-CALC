#ifndef SIGHANDLE_H_
#define SIGHANDEL_H_


/* inclusions */
#include <gtk/gtk.h>

/* symbolic constants */
#define NUMBEROFSIGNALS 20

/* signals : type char * [] : holds all the possible button labels AKA the signals we might interperet with interperet_signal */
extern const char *signals[NUMBEROFSIGNALS];

/* interperet_signal : interperets signals/button labels, and updates the textbox and external infix equation in calculator.c accordingly
 * 
 * Arguments
 *    - signal : type char [] : the signal we are interpereting
 *    - textbox : type GtkTextView * : the GtkTextView AKA textbox that we will update based on the given signal
 */
void interperet_signal(char signal[], GtkTextView *textbox);

#endif
