//  Player.hpp
//  Part 3
//  Emilie Mines & Zach Eichler.

#ifndef Player_hpp
#define Player_hpp
#include <stdio.h>
#include "Cards.hpp"
#include "Orders.hpp"
#include "Map.hpp"
#include <string>
#include <vector>

using namespace std;



class Player {
    // static int variable representing the number of players that exist
    static int num_of_players;
    // private data member: player's Hand object
    Hand hand;
    // private data member: player's OrdersList object
    OrdersList orders_list;
    
public:
    // static member function accessor for num_of_players
    static int get_num_of_players();
    // player's vector of owned territories
    vector<Territory> territory_vector;
    // Hand accessor function
    Hand get_hand();
    // Hand mutator function
    void set_hand(Hand hand);
    // OrdersList accessor function
    OrdersList get_orders_list();
    // OrdersList mutator function
    void set_orders_list(OrdersList ordersList);
    // Player default constructor
    Player();
    // Player constructor
    Player(Hand &hand, OrdersList ordersList);
    // Player copy constructor, performs deep copy
    Player(const Player&);
    // Player destructor
    ~Player();
    // stream insertion operator overloader function that calls a virtual print method to be overloaded
    friend ostream& operator << (ostream& output, const Player &player);
    // virtual print function
    virtual ostream& print(ostream& output) const;
    // assignment operator overloader, performs shallow copy
    virtual const Player& operator=(const Player& player);
    // returns a list of territories to be defended
    vector<Territory> toDefend();
    // returns a list of territories to be attacked
    vector<Territory> toAttack();
    // creates an Order object and puts it in the player's list of orders
    void issueOrder();
    
};


#endif /* Player_hpp */
