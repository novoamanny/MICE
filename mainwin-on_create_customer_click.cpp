#include "mainwin.h"
#include "customer.h"
#include <exception>
#include <stdexcept>
#include <iostream>

void Mainwin::on_create_customer_click() {

    const int WIDTH = 15;
    Gtk::Dialog dialog;
    dialog.set_title("Create a Customer");
    //dialog.set_transient_for(*this);

    // Name 
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(WIDTH);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(WIDTH*4);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    // TODO: Replace this with a Gtk::TextView inside a Gtk::ScrolledWindow
    // Description
    Gtk::HBox b_phone;

    Gtk::Label l_phone{"Phone:"};
    l_phone.set_width_chars(WIDTH);
    b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

    Gtk::Entry e_phone;
    e_phone.set_max_length(WIDTH*4);
    b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

    
    // Show dialog
    dialog.add_button("Cancel", 0);
    dialog.add_button("OK", 1);
    dialog.show_all();

    bool valid_data = false;
    

    while(!valid_data) {
        if (dialog.run() != 1) {
            dialog.close();
            return;
        }

        valid_data = true;
        
        
    }
        Mice::Customer c{e_name.get_text(), e_phone.get_text()};
        _emp->add_customer(c);
        
    
    dialog.close();
}
