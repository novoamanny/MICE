#include "mainwin.h"
#include "emporium.h"
#include <exception>
#include <stdexcept>

void Mainwin::on_file_open_click() {
    try {
        std::ifstream ifs{"emporium.emp", std::ifstream::in};
        _emp = new Mice::Emporium{ifs};
    }

    } catch (std::exception& e) {
        Gtk::MessageDialog dialog{*this, "Unable to open emporium.emp"};
        dialog.set_secondary_text(e.what());
        dialog.run();
        dialog.close();
    }
}