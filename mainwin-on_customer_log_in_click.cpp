#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>

void Mainwin::on_customer_log_in_click() {

    // /////////////////////////////
    // Select Item Type
    Gtk::Dialog dialog_type{"Customer Log In", *this};
    //dialog_type.set_title("Select Item Type");
    const int WIDTH = 15;
    Gtk::Dialog dialog;
    
    // Name 
    Gtk::HBox b_pin;

    Gtk::Label l_pin{"PHONE:"};
    l_pin.set_width_chars(WIDTH);
    b_pin.pack_start(l_pin, Gtk::PACK_SHRINK);

    Gtk::Entry e_pin;
    e_pin.set_max_length(WIDTH*4);
    b_pin.pack_start(e_pin, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_pin, Gtk::PACK_SHRINK);

    // Show dialog
    dialog.add_button("Cancel", 0);
    dialog.add_button("OK", 1);
    dialog.show_all();

    bool valid_data = false;
    double d_cost;
    double d_price;
    int i_max_scoops;

    while(!valid_data) {
        if (dialog.run() != 1) {
            dialog.close();
            return;
        }

        valid_data = true;
        
    }

    bool tmp = true;
    
    /*for (int i = 0; i < _servers.size(); i++){
        if (e_pin.get_text() == _customers[i].phone()){
            Gtk::MessageDialog dialog{*this, "You Are Now Logged In..."};
            dialog.run();
            dialog.close();
        }
        else{
            Gtk::MessageDialog dialog{*this, "Wrong Log In..."};
            dialog.run();
            dialog.close();
        }
    }*/
    
    dialog.close();
}
