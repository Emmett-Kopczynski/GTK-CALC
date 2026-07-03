/* graphicutils : utilities for controlling the calc apps gui
 *
 * Author : Emmett James Kopczynski
 *
 * To Do : DONE 
 *
 * Known Bugs : 
 *
 */

/* inclusions */
#include <gtk/gtk.h>
#include "graphicutils.h"
#include "sighandle.h"
#include <string.h>
#include <stdio.h>

/* run : runs the application and calls the start method */
int run(int argc, char *argv[]){
    GtkApplication *app;
    int status; /* status to be returned */

    app = gtk_application_new ("org.gtk.calculator", G_APPLICATION_DEFAULT_FLAGS); 
    
    g_signal_connect(app, "activate", G_CALLBACK(start), NULL); /* connects application to start */

    status = g_application_run( G_APPLICATION(app), argc, argv); /* runs the application and returns the status */

    g_object_unref(app);

    return status;
}

/* run_button : runs all behevior for pressing a button */
void run_button(GtkWidget *button, gpointer data){
    interperet_signal( ((char *)gtk_button_get_label( GTK_BUTTON ( button ) )), GTK_TEXT_VIEW(data));
}

/* set_text_box : sets the given text box with the given text */
void set_text_box(GtkTextView *textbox, char *text){
    gtk_text_buffer_set_text( gtk_text_view_get_buffer( GTK_TEXT_VIEW( textbox ) ), text, strlen(text) );
} 

/* start : builds the gui of the application */
void start(GtkApplication *app, gpointer user_data){
    
    /* SETUP THE WINDOW */
    GtkWidget *window;
    window = gtk_application_window_new(app); /* builds the window for the app */
    gtk_window_set_default_size (GTK_WINDOW( window ), BUTTONSIZE * 4, BUTTONSIZE * 6);
    gtk_window_set_title(GTK_WINDOW( window ), "Calculator");
    gtk_window_set_resizable(GTK_WINDOW( window ), false);

    /* DECLARE GRID, BUTTON, AND TEXTBOX */
    GtkWidget *button;
    GtkWidget *textbox;
    GtkWidget *grid;

    /* INITIALIZE AND PACK THE GRID INTO WINDOW */
    grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW( window ), grid);

    /* INITIALIZE TEXTBOX AND PLACE IN GRID */
    textbox = gtk_text_view_new(); 
    gtk_text_view_set_editable( GTK_TEXT_VIEW( textbox ), false);
    gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW( textbox )), "", 0);
    gtk_widget_set_size_request(textbox, BUTTONSIZE * 4, BUTTONSIZE);
    gtk_grid_attach( GTK_GRID(grid), textbox, 0, 0, 4, 1);

    /* NOW BUILDING THE GRID OF BUTTONS */
    int i = 0; /* collumn */
    int j = 0; /* row */
    int c = 0; /* total number of buttons placed */
    for(i = 0, j = 1, c = 0; c < NUMBEROFSIGNALS ; i++, c++){
        button = gtk_button_new_with_label(signals[c]);
        gtk_widget_set_size_request(button, BUTTONSIZE, BUTTONSIZE);
        g_signal_connect(button, "clicked", G_CALLBACK(run_button), textbox);
        gtk_grid_attach(GTK_GRID( grid ), button, i, j, 1, 1);
        if(i == 3){
            i = -1; /* i = -1 so that it becomes 0 on the next round */
            j += 1;
        }
    }

    /* FINISH UP */
    gtk_window_present ( GTK_WINDOW (window)); /* sets the present window */
}






