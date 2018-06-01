#ifndef _SERVER_H
#define _SERVER_H

#include <string>
#include <iostream>
#include <fstream>

namespace Mice {

    class Server {
    public:
        Server(std::string name, std::string phone, std::string emp_id, std::string log_pin);
        void save(std::ostream& ost);
        Server(std::istream& ist);
        
        std::string name() const;
        std::string phone() const;
        std::string emp_id() const;
        std::string log_pin() const;
        bool check_log_in() const;
    private:
        std::string _name;
        std::string _phone;
        std::string _emp_id;
        std::string _log_pin;
        bool _log_in = false;
        double _salary = 7.25;
    };
}
std::ostream& operator<<(std::ostream& os, const Mice::Server& server);
#endif