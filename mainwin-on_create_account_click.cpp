#include "mainwin.h"
#include "server.h"
#include <exception>
#include <stdexcept>
#include <iostream>

void Mainwin::on_create_account_click() {

    // /////////////////////////////
    // Select Item Type
    Gtk::Dialog dialog_type{"Select Account Type", *this};
    //Gtk::Dialog dialog_type;
    //dialog_type.set_title("Select Item Type");
    const int WIDTH = 15;

    // Type
    Gtk::HBox b_type;

    Gtk::Label l_type{"Roll:"};
    l_type.set_width_chars(WIDTH);
    b_type.pack_start(l_type, Gtk::PACK_SHRINK);

    // TODO: Replace this with 3 large, colorful buttons
    Gtk::ComboBoxText c_type;
    c_type.set_size_request(WIDTH*10);
    const int SERVER = 0;
    c_type.append("Server");
    const int MANAGER = 1;
    c_type.append("Manager");
    const int CUSTOMER = 2;
    c_type.append("Customer");
    b_type.pack_start(c_type, Gtk::PACK_SHRINK);
    dialog_type.get_vbox()->pack_start(b_type, Gtk::PACK_SHRINK);

    // Show dialog_type
    dialog_type.add_button("Cancel", 0);
    dialog_type.add_button("OK", 1);
    dialog_type.show_all();
    if (dialog_type.run() != 1) {
        dialog_type.close();
        return;
    }

    int type = c_type.get_active_row_number();

    dialog_type.close();

    // //////////////////////////////
    // Define Item

    Gtk::Dialog dialog;
    if (type == SERVER) on_create_server_click();
    else if (type == MANAGER) dialog.set_title("Create Manager");
    else on_create_customer_click();
    dialog.set_transient_for(*this);

   /*// Name 
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

    // Cost
    Gtk::HBox b_emp_id;

    Gtk::Label l_emp_id{"Employee ID:"};
    l_emp_id.set_width_chars(WIDTH);
    b_emp_id.pack_start(l_emp_id, Gtk::PACK_SHRINK);

    Gtk::Entry e_emp_id;
    e_emp_id.set_max_length(WIDTH*4);
    b_emp_id.pack_start(e_emp_id, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_emp_id, Gtk::PACK_SHRINK);

    // Price
    Gtk::HBox b_log_pin;

    Gtk::Label l_log_pin{"Login Pin:"};
    l_log_pin.set_width_chars(WIDTH);
    b_log_pin.pack_start(l_log_pin, Gtk::PACK_SHRINK);

    Gtk::Entry e_log_pin;
    e_log_pin.set_max_length(WIDTH*4);
    b_log_pin.pack_start(e_log_pin, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_log_pin, Gtk::PACK_SHRINK);

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
        
    // Instance item
    if (type == SERVER) {
        Mice::Server c{e_name.get_text(), e_phone.get_text(), e_emp_id.get_text(), e_log_pin.get_text()};
        _servers.push_back(c);
        
    } /*else if (type == MANAGER) {
        Mice::Scoop s{e_name.get_text(), e_desc.get_text(), d_cost, d_price};
        _scoops.push_back(s);
        std::cout << s << std::endl;
    } else {
        Mice::Topping t{e_name.get_text(), e_desc.get_text(), d_cost, d_price, 0};
        _toppings.push_back(t);
        std::cout << t << std::endl;
    }*/
    
    dialog.close();
}
