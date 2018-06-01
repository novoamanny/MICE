#ifndef EMPORIUM_H
#define EMPORIUM_H

#include "container.h"
#include "scoop.h"
#include "topping.h"
#include "serving.h"
#include "server.h"
#include "customer.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace Mice {
    class Emporium{
        public:
            Emporium(std::string name);
            Emporium(std::istream& ist);
            void save(std::ostream& ost);

            std::string name();

        int num_containers();
        int num_scoops();
        int num_toppings();
        //int num_orders();
        int num_servers();
        int num_customers();
        
        Container& container(int index);
        Scoop& scoop(int index);
        Topping& topping(int index);
        //Order& order(int index);
        Server& server(int index);
        Customer& customer(int index);

        void add_container(Container container);
        void add_scoop(Scoop scoop);
        void add_topping(Topping topping);
        //void add_order(Order order);
        void add_server(Server server);
        void add_customer(Customer customer);

            private:
            std::string _name;

            std::vector<Mice::Container> _containers;
            std::vector<Mice::Scoop> _scoops;
            std::vector<Mice::Topping> _toppings;
            std::vector<Mice::Server> _servers;
            //std::vector<Mice::Order> _orders;
            std::vector<Mice::Customer> _customers;
    };
}
#endif