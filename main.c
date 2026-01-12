#include <gtk/gtk.h>

GdkPixbuf *create_pixbuf(const gchar * filename);


static void print_hello (GtkWidget *widget, gpointer   data)
{
  g_print ("Hello World\n");
}

gboolean user_function(GtkWidget *widget, GdkEvent *event, gpointer  user_data)
{
	g_print("Moving\n");
}




static void activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GdkPixbuf *icon;
  
  GtkWidget *menubar;
  GtkWidget *fileMenu;
  GtkWidget *fileMi;
  GtkWidget *quitMi;
  
 // GtkWidget *MenuBar = gtk_box_new()
  
  
  
  icon = create_pixbuf("L.jpg");

  /* create a new window, and set its title */
  window = gtk_application_window_new (app);
  gtk_window_set_icon(GTK_WINDOW (window), icon);
  gtk_window_set_title (GTK_WINDOW (window), "Led Sign Studio");
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
  gtk_container_set_border_width (GTK_CONTAINER (window), 0);
  
GtkWidget *grid = gtk_grid_new();
gtk_grid_set_row_homogeneous(GTK_GRID(grid), FALSE);
gtk_grid_set_column_homogeneous(GTK_GRID(grid), FALSE);
gtk_container_add(GTK_CONTAINER(window), grid);



  menubar = gtk_menu_bar_new();
  fileMenu = gtk_menu_new();

  fileMi = gtk_menu_item_new_with_label("File");
  quitMi = gtk_menu_item_new_with_label("Quit");

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);
  
  
  
GtkWidget *notebook1;
GtkWidget *notebook2;
GtkWidget *notebook3;

GtkWidget *text1 = gtk_text_view_new(); GtkWidget *label1 = gtk_label_new("place holder");
GtkWidget *text2 = gtk_text_view_new(); GtkWidget *label2 = gtk_label_new("place holder");
GtkWidget *text3 = gtk_text_view_new(); GtkWidget *label3 = gtk_label_new("place holder");  
  
notebook1 = gtk_notebook_new();
notebook2 = gtk_notebook_new();
notebook3 = gtk_notebook_new();

gtk_notebook_append_page(GTK_NOTEBOOK(notebook1), text1, label1);
gtk_notebook_append_page(GTK_NOTEBOOK(notebook2), text2, label2);
gtk_notebook_append_page(GTK_NOTEBOOK(notebook3), text3, label3);
//gtk_notebook_set_show_tabs(GTK_NOTEBOOK(notebook3), FALSE);

/*GtkWidget *frame1 = gtk_frame_new (NULL);
GtkWidget *frame2 = gtk_frame_new (NULL);
gtk_frame_set_shadow_type (GTK_FRAME (frame1), GTK_SHADOW_IN);
gtk_frame_set_shadow_type (GTK_FRAME (frame2), GTK_SHADOW_IN);
GtkWidget *frame3 = gtk_frame_new (NULL);
gtk_frame_set_shadow_type (GTK_FRAME (frame3), GTK_SHADOW_IN);
*/

GtkWidget* Vpaned = gtk_paned_new(GTK_ORIENTATION_VERTICAL);
GtkWidget* Hpaned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
//GdkWindow* rucka = gtk_paned_get_handle_window(GTK_PANED(Vpaned));
//GtkWidget* rucica = gtk_widget_new()

gtk_paned_add1(GTK_PANED(Vpaned), Hpaned);
gtk_paned_add2(GTK_PANED(Vpaned), notebook3);
gtk_paned_add1(GTK_PANED(Hpaned), notebook1);
gtk_paned_add2(GTK_PANED(Hpaned), notebook2);

gtk_widget_set_hexpand(Vpaned, TRUE);
gtk_widget_set_hexpand(Hpaned, TRUE);
//gtk_widget_set_hexpand(notebook3, TRUE);
gtk_widget_set_vexpand(Vpaned, TRUE);
gtk_widget_set_vexpand(Hpaned, TRUE);
//gtk_widget_set_vexpand (notebook3, TRUE);
gtk_paned_set_position(GTK_PANED(Vpaned), 100);

//gtk_widget_add_events(GTK_WIDGET(rucka), GDK_STRUCTURE_MASK);
//g_signal_connect(G_OBJECT(window), "configure-event", G_CALLBACK(user_function), NULL);
gint a = gtk_widget_get_events(GTK_WIDGET(Vpaned));



 
gtk_grid_attach(GTK_GRID(grid), Vpaned, 0, 1, 1, 1);
gtk_grid_attach(GTK_GRID(grid), menubar, 0, 0, 1, 1);

GtkWidget *entry = gtk_entry_new();
gtk_grid_attach(GTK_GRID(grid), entry, 0, 2, 1, 1);
gtk_widget_set_hexpand(entry, TRUE);

//gtk_container_add(GTK_CONTAINER(window), grid);


  
gtk_widget_show_all(window);


}

int main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}


// funkcija za formiranje ikonice u titlebaru i taskbaru
GdkPixbuf *create_pixbuf(const gchar * filename)
{ 
   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   
   if (!pixbuf) 
   {    
		fprintf(stderr, "%s\n", error->message);
		g_error_free(error);
   }

   return pixbuf;
}
