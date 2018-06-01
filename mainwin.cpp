#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>

Mainwin::Mainwin() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(800, 600);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //
    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         N E W   E M P O R I U M
    // (Owner) “Create a New Emporium” Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Emporium", true));
    //menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_new_game_click));
    filemenu->append(*menuitem_new);

    //         O P E N   E M P O R I U M
    // (Owner) “Open an Emporium File” Append Open to the File menu
    menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_file_open_click));
    filemenu->append(*menuitem_open);

    //         S A V E   E M P O R I U M
    // (Owner) “Save an Emporium File” Append Save to the File menu
    menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_file_save_click));
    filemenu->append(*menuitem_save);

    //         E A S T E R   E G G
    // (TODO: Test Only) “Create a New Emporium” Append Easter Egg to the File menu
    Gtk::MenuItem *menuitem_easteregg = Gtk::manage(new Gtk::MenuItem("_Easter Egg", true));
    menuitem_easteregg->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_easteregg_click));
    filemenu->append(*menuitem_easteregg);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    filemenu->append(*menuitem_quit);

    //
    //     C R E A T E
    // Create a Create menu and add to the menu bar
    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
    menubar->append(*menuitem_create);
    Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*createmenu);

    //         O R D E R
    // (All) “Create Delicious Ice Cream Treats” Append Order to the Create menu
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order...", true));
    //menuitem_order->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    createmenu->append(*menuitem_order);

    //         C U S T O M E R
    // (Server, Manager, Owner) “Create a New Customer” Append Customer to the Create menu
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer...", true));
    menuitem_customer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_customer_click));
    createmenu->append(*menuitem_customer);

    //         I T E M 
    // (Owner, Manager) “Create a New Container, Ice Cream Flavor, or Topping” Append Item to the Create menu
    Gtk::MenuItem *menuitem_item = Gtk::manage(new Gtk::MenuItem("_Item...", true));
    menuitem_item->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_item_click));
    createmenu->append(*menuitem_item);

    //         S E R V E R
    // (Owner, Manager) “Add a New Employee” Append Server to the Create menu
    Gtk::MenuItem *menuitem_server = Gtk::manage(new Gtk::MenuItem("_Server...", true));
    menuitem_server->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_server_click));
    createmenu->append(*menuitem_server);

     //
    //     L O G   I N
    // Create a Log In menu and add to the menu bar
    /*Gtk::MenuItem *menuitem_log_in = Gtk::manage(new Gtk::MenuItem("_Log In", true));
    menubar->append(*menuitem_log_in);
    Gtk::Menu *log_in_menu = Gtk::manage(new Gtk::Menu());
    menuitem_log_in->set_submenu(*log_in_menu);

    //         S E R V E R   L O G   I N 
    //  Append to Log In
    Gtk::MenuItem *menuitem_server_log = Gtk::manage(new Gtk::MenuItem("_Server...", true));
    menuitem_log_in->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_server_log_in_click));
    log_in_menu->append(*menuitem_server_log);

    //         C U S T O M E R   L O G   I N 
    //  Append to Log In
    Gtk::MenuItem *menuitem_customer_log = Gtk::manage(new Gtk::MenuItem("_Customer...", true));
    menuitem_log_in->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_customer_log_in_click));
    log_in_menu->append(*menuitem_customer_log);*/

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_about_click));
    helpmenu->append(*menuitem_about);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //     N E W   E M P O R I U M
    // Add a new emporium icon
    Gtk::ToolButton *new_emporium_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_emporium_button->set_tooltip_markup("Create a New Emporium");
    //new_emporium_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_new_emporium_click));
    toolbar->append(*new_emporium_button);

    //     C R E A T E   O R D E R
    // Add a Create Order icon
    Gtk::Image *create_order_button_image = Gtk::manage(new Gtk::Image("new_order.png"));
    Gtk::ToolButton *create_order_button = Gtk::manage(new Gtk::ToolButton(*create_order_button_image));
    create_order_button->set_tooltip_markup("Create a new order");
    //create_order_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    toolbar->append(*create_order_button);

    //     C R E A T E   C R E A T E   I T E M
    // Add a Create Item icon
    Gtk::Image *create_item_button_image = Gtk::manage(new Gtk::Image("create_item.png"));
    Gtk::ToolButton *create_item_button = Gtk::manage(new Gtk::ToolButton(*create_item_button_image));
    create_item_button->set_tooltip_markup("Create a new item");
    create_item_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_item_click));
    toolbar->append(*create_item_button);

    //  L O G   I N
    // Add a Log In icon
    Gtk::Image *create_log_in_button_image = Gtk::manage(new Gtk::Image("log_in.png"));
    Gtk::ToolButton *create_log_in_button = Gtk::manage(new Gtk::ToolButton(*create_log_in_button_image));
    create_log_in_button->set_tooltip_markup("Log In");
    create_log_in_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_log_in_click));
    toolbar->append(*create_log_in_button);

    // C R E A T E   A C C O U N T
    // Add a Accont icon
    Gtk::Image *create_account_button_image = Gtk::manage(new Gtk::Image("add_patron.png"));
    Gtk::ToolButton *create_account_button = Gtk::manage(new Gtk::ToolButton(*create_account_button_image));
    create_account_button->set_tooltip_markup("Create a new account");
    create_account_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_account_click));
    toolbar->append(*create_account_button);


    //     Q U I T
    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit MICE");
    quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);

    // Make the box and everything in it visible
    vbox->show_all();
    _emp = new Mice::Emporium{"Default"};
    set_title("Mav's Ice Cream Emporium");
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click() {
    hide();
}

// void Mainwin::on_about_click() {
// }

/*void Mainwin::on_create_order_click() {
    try {
        // Create a new serving (NOT an order yet!)
        int c = 0;
        while(c < 5){
        Mice::Serving serving = create_serving();
        _servings.push_back(serving);
        std::cout << serving << std::endl;  // TODO: Temporary - replace with confirmation dialog
        c++;
        }
    } catch(std::runtime_error e) { // User canceled order
    }
}*/



/*void Mainwin::on_easteregg_click() {
        _containers.push_back(
            Mice::Container{"Cone", "Crispy airy delight", 0.25, 0.50, 2});
        _containers.push_back(
            Mice::Container{"Waffle Cone", "Crunchy wrapped waffle cake", 0.35, 0.75, 3});
        _scoops.push_back(
            Mice::Scoop{"Chocolate", "Rich smooth chocolate ice cream", 0.20, 0.50});
        _scoops.push_back(
            Mice::Scoop{"Vanilla", "Real vanilla bean ice cream", 0.20, 0.50});
        _scoops.push_back(
            Mice::Scoop{"Strawberry", "Chunks of strawberry wrapped in vanilla ice cream", 0.20, 0.50});
        _toppings.push_back(
            Mice::Topping{"Cherry", "Classic marichino cherry", 0.1, 0.2, 0});
        _toppings.push_back(
            Mice::Topping{"Chocolate Sauce", "Rich thick chocolate", 0.1, 0.25, 0});
        _toppings.push_back(
            Mice::Topping{"Whipped Cream", "Real sweet cream whipped to perfection", 0.1, 0.2, 0});

        // Display acknowledgement
        Gtk::MessageDialog dialog{*this, "Added 2 containers, 3 scoops, and 3 toppings"};
        dialog.run();
        dialog.close();
 } */

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog{};
    dialog.set_transient_for(*this);
    dialog.set_program_name("Mav's Ice Cream Emporium");
    auto logo = Gdk::Pixbuf::create_from_file("logo.png");
    dialog.set_logo(logo);
    dialog.set_version("Sprint 3");
    dialog.set_copyright("Copyright 2017");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Manuel Novoa"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {"Logo by Schmidsi, https://pixabay.com/en/ice-ice-cream-cone-ice-ball-pink-1429596/",
                                            "Ice Cream Cone by Patrick Trouvé from the Noun Project, https://thenounproject.com/term/ice-cream-cone/63026/"};
    dialog.set_artists(artists);
    dialog.run();
}


