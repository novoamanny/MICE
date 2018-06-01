#include "customer.h"
#include <iostream>
#include <iomanip>

namespace Mice {

    Customer::Customer(std::string name, std::string phone)
        : _name{name}, _phone{phone} { }
    
    std::string Customer::name() const{
        return _name;
    }    
    std::string Customer::phone() const{
        return _phone;
    }
    
    void Customer::save(std::ostream& ost) {
    ost << "#" << std::endl << "CUSTOMER" << std::endl; // header
    ost << _name << std::endl;
    //ost << _id << std::endl;
    ost << _phone << std::endl;
}

Customer::Customer(std::istream& ist) {
    getline(ist, _name);
    getline(ist, _phone);
}

    
}