//  CardsDriver.cpp
//  Part 5
//  Emilie Mines & Zach Eichler.

#include <stdio.h>
#include <iostream>
#include "Cards.hpp"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

// Driver file creates a deck of Card objects,
// then creates a hand object that is filled by drawing cards from the deck,
// then calls the play method of all cards in the hand.

int main()
{
 
    // create seed for random number
    srand((unsigned int) time(NULL));
    
    Deck deck(10);
    
    
    Card& drawn = deck.draw();
    cout << "\nDrawn card: "  << drawn << endl;
    
    // drawn.play();
    
    Hand hand(7, deck);

    //Card card;
    //cout << card << endl;
    
    //SpyCard spy;
    //cout << spy << endl;
    
    cout << "\nPlaying cards in hand: " << endl;
    for(int i = 0; i < hand.get_hand_size(); i++)
    {
        
        Card* card_to_play;
        card_to_play = hand.hand_vector[i];
        card_to_play->play();
    }

    return 0;
}

