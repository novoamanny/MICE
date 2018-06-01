#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <string>
#include <iostream>
#include <fstream>
//Add visit points for customers
namespace Mice {

    class Customer {
    public:
        Customer(std::string name, std::string phone);
        std::string name() const;
        std::string phone() const;
        void save(std::ostream& ost);
        Customer(std::istream& ist);
        //void visit();
    private:
        std::string _name;
        std::string _phone;
        //int _visit;
    };
}
std::ostream& operator<<(std::ostream& os, const Mice::Customer& customer);
#endif