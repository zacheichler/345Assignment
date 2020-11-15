//  PlayerDriver.cpp
//  Part 3
//  Emilie Mines & Zach Eichler.

#include <stdio.h>
#include <iostream>
#include "Player.hpp"
#include <string>
#include <vector>


// Implements a Player Object

int main() {

    
    Player player1;
    
    //Territory ter1(1, 2, 3);
    //Territory ter2(2, 2, 3);
    //Territory ter3(3, 2, 3);
    //cout << ter1 << endl;
    //vector<Territory> tervec = {ter1, ter2, ter3};
    //printTerritoryVector(tervec);
    

    Deck deck(10);
    Hand hand(5, deck);
    
    player1.set_hand(hand);
    //player1.get_hand();
    
    //DeployOrder order;
    
    player1.issueOrder();
    
    cout << player1 << endl;
    
    return 0;
}
