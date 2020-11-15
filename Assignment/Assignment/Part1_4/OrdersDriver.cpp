//  OrdersDriver.cpp
//  Part 4
//  Emilie Mines & Zach Eichler.


#include <stdio.h>
#include <iostream>
#include "Orders.hpp"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

 
int main() {
    
    //initialize orderlist
    OrdersList orders;
    
    //pushing one of each type to order list
    orders.listOfOrders.push_back(new DeployOrder);
    orders.listOfOrders.push_back(new AdvanceOrder);
    orders.listOfOrders.push_back(new BombOrder);
    orders.listOfOrders.push_back(new BlockadeOrder);
    orders.listOfOrders.push_back(new AirliftOrder);
    orders.listOfOrders.push_back(new NegotiateOrder);
    
    
    // iterate over order list to show the overloaded virtual function works
    list<Order*>::iterator i;
    
    //prints order
    for (i = orders.listOfOrders.begin(); i != orders.listOfOrders.end(); ++i) {
        cout << **i << endl;
    }
 
 
    return 0;
}
