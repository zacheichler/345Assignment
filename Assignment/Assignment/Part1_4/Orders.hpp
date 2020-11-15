// GOOD
// OrdersList.hpp
//  Part 4
//  Emilie Mines & Zach Eichler.

#ifndef Orders_hpp
#define Orders_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <list>


using namespace std;

// Order class, represents an order object
class Order {
    //static int variable that represents number of orders that exist
    static int num_of_orders;
    
public:
    // Order constructor
    Order();
    // Order copy constructor, performs deep copy
    Order(const Order&);
    // Order destructor
    ~Order();
    // stream insertion operator overloader function that calls a virtual print method to be overloaded
    friend ostream& operator << (ostream& output, const Order &order);
    // virtual print function that is overridden by all order subclasses, outputs a string describing the order. If the order has been executed, it should also output the effect of the order.
    virtual ostream& print(ostream& output) const;
    // assignment operator overloader, performs shallow copy
    virtual const Order& operator=(const Order& order);
    // static member function accessor for num_of_orders
    static int get_num_of_orders();
    // validate function used to validate the order
    virtual bool validate();
    // execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
    virtual void execute();
};


// OrdersList class, contains a list of Order objects
class OrdersList {
    
public:
    // public data member: list of Order pointer objects
    list<Order*> listOfOrders;
    // OrdersList default constructor
    OrdersList();
    // OrdersList copy constructor, performs deep copy
    OrdersList(const OrdersList&);
    // OrdersList destructor
    ~OrdersList();
    // stream insertion operator overloader function that calls a virtual print method to be overloaded
    friend ostream& operator << (ostream& output, const OrdersList &ordersList);
    // virtual print function that outputs a string describing the OrdersList
    virtual ostream& print(ostream& output) const;
    // assignment operator overloader, performs shallow copy
    virtual const OrdersList& operator=(const OrdersList& ordersList);
    // remove function that deletes an order from the list
    void remove();
    // move function that moves an order in the list of orders
    void move();
};



// DeployOrder class, subclass of Order
class DeployOrder : public Order {
public:
    // DeployOrder default constructor
    DeployOrder();
    // DeployOrder copy constructor, performs deep copy
    DeployOrder(const DeployOrder&);
    // DeployOrder destructor
    ~DeployOrder();
    // virtual print function that overrides the Order base function
    virtual ostream& print(ostream& output) const override;
    // assignment operator overloader, performs shallow copy
    virtual const DeployOrder& operator=(const DeployOrder& deployOrder);
    // validate function used to validate the order
    virtual bool validate() override;
    // execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
    virtual void execute() override;

};

// AdvanceOrder class, subclass of Order
class AdvanceOrder : public Order {
public:
    // AdvanceOrder default constructor
    AdvanceOrder();
    // AdvanceOrder copy constructor, performs deep copy
    AdvanceOrder(const AdvanceOrder&);
    // AdvanceOrder destructor
    ~AdvanceOrder();
    // virtual print function that overrides the Order base function
    virtual ostream& print(ostream& output) const override;
    // assignment operator overloader, performs shallow copy
    virtual const AdvanceOrder& operator=(const AdvanceOrder& advanceOrder);
    // validate function used to validate the order
    virtual bool validate() override;
    // execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
    virtual void execute() override;
};

// BombOrder class, subclass of Order
class BombOrder : public Order {
public:
    // BombOrder default constructor
    BombOrder();
    // BombOrder copy constructor, performs deep copy
    BombOrder(const BombOrder&);
    // BombOrder destructor
    ~BombOrder();
    // virtual print function that overrides the Order base function
    virtual ostream& print(ostream& output) const override;
    // assignment operator overloader, performs shallow copy
    virtual const BombOrder& operator=(const BombOrder& bombOrder);
    // validate function used to validate the order
    virtual bool validate() override;
    // execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
    virtual void execute() override;
};

// BlockadeOrder class, subclass of Order
class BlockadeOrder : public Order {
public:
    // BlockadeOrder default constructor
    BlockadeOrder();
    // BlockadeOrder copy constructor, performs deep copy
    BlockadeOrder(const BlockadeOrder&);
    // BlockadeOrder destructor
    ~BlockadeOrder();
    // virtual print function that overrides the Order base function
    virtual ostream& print(ostream& output) const override;
    // assignment operator overloader, performs shallow copy
    virtual const BlockadeOrder& operator=(const BlockadeOrder& blockadeOrder);
    // validate function used to validate the order
    virtual bool validate() override;
    // execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
    virtual void execute() override;
};

// AirliftOrder class, subclass of Order
class AirliftOrder : public Order {
public:
    // AirliftOrder default constructor
    AirliftOrder();
    // AirliftOrder copy constructor, performs deep copy
    AirliftOrder(const AirliftOrder&);
    // AirliftOrder destructor
    ~AirliftOrder();
    // virtual print function that overrides the Order base function
    virtual ostream& print(ostream& output) const override;
    // assignment operator overloader, performs shallow copy
    virtual const AirliftOrder& operator=(const AirliftOrder& airliftOrder);
    // validate function used to validate the order
    virtual bool validate() override;
    // execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
    virtual void execute() override;
};

// NegotiateOrder class, subclass of Order
class NegotiateOrder : public Order {
public:
    // NegotiateOrder default constructor
    NegotiateOrder();
    // NegotiateOrder copy constructor, performs deep copy
    NegotiateOrder(const NegotiateOrder&);
    // NegotiateOrder destructor
    ~NegotiateOrder();
    // virtual print function that overrides the Order base function
    virtual ostream& print(ostream& output) const override;
    // assignment operator overloader, performs shallow copy
    virtual const NegotiateOrder& operator=(const NegotiateOrder& negotiateOrder);
    // validate function used to validate the order
    virtual bool validate() override;
    // execute function: first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state
    virtual void execute() override;
};






 
#endif /* Orders_hpp */


