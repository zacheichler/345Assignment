//  OrdersList.cpp
//  Part 4
//  Emilie Mines & Zach Eichler.


#include "Orders.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// ORDER FUNCTIONS

// Order constructor
Order::Order() {
    num_of_orders++;
}

// Order copy constructor, performs deep copy
Order::Order(const Order &order2) {
    
}

// Order destructor
Order::~Order() {
    num_of_orders--;
}

// static member function accessor for num_of_orders
int Order::get_num_of_orders() {
    return num_of_orders;
}

// instantiates static variable num_of_orders
int Order::num_of_orders = 0;

// implements a stream insertion operator that calls a virtual print method to be overloaded
// uses pass by reference on Order objects
ostream& operator << (ostream& output, const Order &order) {
    return order.print(output);
}

// outputs a string describing the Card, depending on the subclass of Card
ostream& Order::print(ostream& output) const {
    output << "\nORDER PRINT";
    return output;
}

// assignment operator overloader, performs shallow copy
const Order& Order::operator=(const Order& order) {
    
    return *this;
}

// validate function used to validate the order
bool Order::validate() {
    
    return true;
}

// execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
void Order::execute() {
    
}


// ORDERSLIST FUNCTIONS

// OrdersList constructor
OrdersList::OrdersList() {
}

// OrdersList copy constructor, performs deep copy
OrdersList::OrdersList(const OrdersList &ordersList) :
listOfOrders(ordersList.listOfOrders) {
}

// OrdersList destructor
OrdersList::~OrdersList() {

}
    
// implements a stream insertion operator that calls a virtual print method to be overloaded
// uses pass by reference on OrdersList objects
ostream& operator << (ostream& output, const OrdersList &ordersList) {
    return ordersList.print(output);
}

// outputs a string describing the OrdersList
ostream& OrdersList::print(ostream& output) const {
    output << "\nORDERSLIST PRINT";
    return output;
}

// assignment operator overloader, performs shallow copy
const OrdersList& OrdersList::operator=(const OrdersList& ordersList) {
    
    return *this;
}

// remove function that deletes an order from the list
void OrdersList::remove() {
    
}

// move function that moves an order in the list of orders
void OrdersList::move() {
        
}


// ORDER SUBCLASS FUNCTIONS

// DeployOrder default constructor
DeployOrder::DeployOrder() {
    
}

// DeployOrder copy constructor, performs deep copy
DeployOrder::DeployOrder(const DeployOrder&) {
    
}

// DeployOrder destructor
DeployOrder::~DeployOrder() {
    
}

// virtual print function that overrides the Order base function
ostream& DeployOrder::print(ostream& output) const {
    output << "Deploy Order\n";
    return output;
}

// assignment operator overloader, performs shallow copy
const DeployOrder& DeployOrder::operator=(const DeployOrder& deployOrder) {
    
    return *this;
}

// validate function used to validate the order
// If the target territory does not belong to the player that issued the order, the order is invalid.
bool DeployOrder::validate() {
    
    return true;
}

// execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
// A deploy order tells a certain number of armies taken from the reinforcement pool to deploy to a target territory owned by the player issuing this order.
void DeployOrder::execute() {
    this->validate();
    
}


// AdvanceOrder default constructor
AdvanceOrder::AdvanceOrder() {
    
}

// AdvanceOrder copy constructor, performs deep copy
AdvanceOrder::AdvanceOrder(const AdvanceOrder&) {
    
}

// AdvanceOrder destructor
AdvanceOrder::~AdvanceOrder() {
    
}

// virtual print function that overrides the Order base function
ostream& AdvanceOrder::print(ostream& output) const {
    output << "Advance Order\n";
    return output;
}

// assignment operator overloader, performs shallow copy
const AdvanceOrder& AdvanceOrder::operator=(const AdvanceOrder& advanceOrder) {
    
    return *this;
}

// validate function used to validate the order
bool AdvanceOrder::validate() {
    
    return true;
}

// execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
void AdvanceOrder::execute() {
    this->validate();
    
}


// BombOrder default constructor
BombOrder::BombOrder() {
    
}

// BombOrder copy constructor, performs deep copy
BombOrder::BombOrder(const BombOrder&) {
    
}

// BombOrder destructor
BombOrder::~BombOrder() {
    
}

// virtual print function that overrides the Order base function
ostream& BombOrder::print(ostream& output) const {
    output << "Bomb Order\n";
    return output;
}

// assignment operator overloader, performs shallow copy
const BombOrder& BombOrder::operator=(const BombOrder& bombOrder) {
    
    return *this;
}

// validate function used to validate the order
bool BombOrder::validate() {
    
    return true;
}

// execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
void BombOrder::execute() {
    this->validate();
    
}


// BlockadeOrder default constructor
BlockadeOrder::BlockadeOrder() {
    
}

// BlockadeOrder copy constructor, performs deep copy
BlockadeOrder::BlockadeOrder(const BlockadeOrder&) {
    
}

// BlockadeOrder destructor
BlockadeOrder::~BlockadeOrder() {
    
}

// virtual print function that overrides the Order base function
ostream& BlockadeOrder::print(ostream& output) const {
    output << "Blockade Order\n";
    return output;
}

// assignment operator overloader, performs shallow copy
const BlockadeOrder& BlockadeOrder::operator=(const BlockadeOrder& blockadeOrder) {
    
    return *this;
}

// validate function used to validate the order
bool BlockadeOrder::validate() {
    
    return true;
}

// execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
void BlockadeOrder::execute() {
    this->validate();
    
}


// AirliftOrder default constructor
AirliftOrder::AirliftOrder() {
    
}

// AirliftOrder copy constructor, performs deep copy
AirliftOrder::AirliftOrder(const AirliftOrder&) {
    
}

// AirliftOrder destructor
AirliftOrder::~AirliftOrder() {
    
}

// virtual print function that overrides the Order base function
ostream& AirliftOrder::print(ostream& output) const {
    output << "Airlift Order\n";
    return output;
}

// assignment operator overloader, performs shallow copy
const AirliftOrder& AirliftOrder::operator=(const AirliftOrder& airliftOrder) {
    
    return *this;
}

// validate function used to validate the order
bool AirliftOrder::validate() {
    
    return true;
}

// execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
void AirliftOrder::execute() {
    this->validate();
    
}


// NegotiateOrder default constructor
NegotiateOrder::NegotiateOrder() {
    
}

// NegotiateOrder copy constructor, performs deep copy
NegotiateOrder::NegotiateOrder(const NegotiateOrder&) {
    
}

// AirliftOrder destructor
NegotiateOrder::~NegotiateOrder() {
    
}

// virtual print function that overrides the Order base function
ostream& NegotiateOrder::print(ostream& output) const {
    output << "Negotiate Order\n";
    return output;
}

// assignment operator overloader, performs shallow copy
const NegotiateOrder& NegotiateOrder::operator=(const NegotiateOrder& negotiateOrder) {
    
    return *this;
}

// validate function used to validate the order
bool NegotiateOrder::validate() {
    
    return true;
}

// execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
void NegotiateOrder::execute() {
    this->validate();
    
}

