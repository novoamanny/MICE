#include "server.h"
#include <iostream>
#include <iomanip>

namespace Mice {

    Server::Server(std::string name, std::string phone, std::string emp_id, std::string log_pin)
        : _name{name}, _phone{phone}, _emp_id{emp_id}, _log_pin{log_pin} { }
    
    std::string Server::name() const{
        return _name;
    }    
    std::string Server::phone() const{
        return _phone;
    }
    std::string Server::emp_id() const{
        return _emp_id;
    }
    std::string Server::log_pin() const{
        return _log_pin;
    }
    bool Server::check_log_in() const{
        return _log_in;
    }

    void Server::save(std::ostream& ost) {
    ost << "#" << std::endl << "SERVER" << std::endl; // header
    ost << _name << std::endl;
    ost << _emp_id << std::endl;
    ost << _log_pin << std::endl;
    ost << _phone << std::endl;
    ost << _salary << std::endl;
    //ost << _num_orders << std::endl;
}

Server::Server(std::istream& ist) { 
    getline(ist, _name);
    getline(ist, _emp_id);
    getline(ist, _log_pin);
    getline(ist, _phone);
    ist >> _salary; ist.ignore();
}

    
}