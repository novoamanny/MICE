#include "mainwin.h"
#include "emporium.h"
#include <exception>
#include <stdexcept>


void Mainwin::on_file_save_click() {
    try {
        std::ofstream ofs{"emporium.emp", std::ofstream::out};
        _emp->save(ofs);
    } catch (std::exception& e) {
        Gtk::MessageDialog dialog{*this, "Unable to save emporium.emp"};
        dialog.set_secondary_text(e.what());
        dialog.run();
        dialog.close();
    }
}

