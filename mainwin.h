#ifndef MAINWIN_H
#define MAINWIN_H

#include "container.h"
#include "scoop.h"
#include "topping.h"
#include "serving.h"
#include "server.h"
#include "customer.h"
#include "emporium.h"
#include <gtkmm.h>
#include <string>

class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        //void on_file_new_click();                   // Create a new Emporium
        //void on_create_order_click();                 // Create a new order
        void on_file_save_click();
        void on_file_open_click();
        void on_create_customer_click();            // Create a new customer
        void on_create_item_click();                  // Create a new item
        void on_create_account_click();
        void on_create_server_click();
        void on_log_in_click();
        void on_server_log_in_click();
        void on_customer_log_in_click();              // Create a new server
        void on_about_click();                        // Display About dialog
        void on_quit_click();                         // Exit the program
        void on_easteregg_click();                    // TODO: For test only
    private:
        Gtk::MenuItem *menuitem_easteregg;
        Gtk::MenuItem *menuitem_quit;
        Gtk::MenuItem *menuitem_save;
        Gtk::MenuItem *menuitem_open;
        Gtk::MenuItem *menuitem_customer;
        Gtk::MenuItem *menuitem_item;
        Gtk::MenuItem *menuitem_server;

        
        //void create_order();                        // Create a new order
        Mice::Serving create_serving();               // Create a new serving
        int select_container();                       // Select a container index
        int select_scoop();                           // Select a scoop index
        int select_topping();                         // Select a container index
        int select_from_vector
            (std::vector<std::string> names, 
             std::string title);                      // Select from a list of strings

        Mice::Emporium* _emp;
};
#endif 

