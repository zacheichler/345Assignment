//  Player.cpp
//  Part 3
//  Emilie Mines & Zach Eichler.

#include "Player.hpp"
#include "Cards.hpp"
#include "Orders.hpp"
#include "Map.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// instantiates static variable num_of_players
int Player::num_of_players = 0;

// static member function accessor for num_of_players
int Player::get_num_of_players() {
    return num_of_players;
}

// Hand accessor function
Hand Player::get_hand() {
    return hand;
}

// Hand mutator function
void Player::set_hand(Hand hand) {
    this->hand = hand;
}

// OrdersList accessor function
OrdersList Player::get_orders_list() {
    return orders_list;
}

// OrdersList mutator function
void Player::set_orders_list(OrdersList ordersList) {
    this->orders_list = orders_list;
}

// Player default constructor
Player::Player() {
    num_of_players++;
}

// Player constructor
Player::Player(Hand &hand, OrdersList ordersList) {
    num_of_players++;
    this->hand = hand;
    this->orders_list = ordersList;
}

// Player copy constructor, performs deep copy
Player::Player(const Player&) {
    
}

// Player destructor
Player::~Player() {
    num_of_players--;
}

// stream insertion operator overloader function that calls a virtual print method to be overloaded
ostream& operator << (ostream& output, const Player &player) {
    return player.print(output);
}

// virtual print function
ostream& Player::print(ostream& output) const {
    output << "\nPlayer Print";
    cout << hand << endl;
    cout << orders_list << endl;
    return output;
}

// assignment operator overloader, performs shallow copy
const Player& Player::operator=(const Player& player) {
    
    return *this;
}

// returns a list of territories to be defended
vector<Territory> toDefend() {
    Territory ter1(1, 1, 1, 1);
    Territory ter2(2, 2, 2, 2);
    Territory ter3(3, 3, 3, 3);
       
    vector<Territory> sample_territory_vector = {ter1, ter2, ter3};
    return sample_territory_vector;
}

// returns a list of territories to be attacked
vector<Territory> toAttack() {
    Territory ter4(4, 4, 4, 4);
    Territory ter5(5, 5, 5, 5);
    Territory ter6(6, 6, 6, 6);
    
    vector<Territory> sample_territory_vector = {ter4, ter5, ter6};
    return sample_territory_vector;
}

// creates an Order object and puts it in the player's list of orders
void Player::issueOrder() {

    orders_list.listOfOrders.push_back(new Order);

}





