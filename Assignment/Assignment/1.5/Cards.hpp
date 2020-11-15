// GOOD
// Cards.hpp
//  Part 5
//  Emilie Mines & Zach Eichler.

#ifndef Cards_hpp
#define Cards_hpp
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Card class, represents a card object
class Card {
    // static int variable that represents number of cards that exist
    static int num_of_cards;
    
public:
    // static member function accessor for num_of_cards
    static int get_num_of_cards();
    // virtual base play function to be overloaded depending on subclass of Card
    virtual void play();
    // Card constructor
    Card();
    // Card copy constructor, performs deep copy
    Card(const Card&);
    // Card destructor
    ~Card();
    // stream insertion operator overloader function that calls a virtual print method to be overloaded
    friend ostream& operator << (ostream& output, const Card &card);
    // virtual print function that is overridden by all card subclasses
    virtual ostream& print(ostream& output) const;
    // assignment operator overloader, performs shallow copy
    virtual const Card& operator=(const Card& card);
};



// Deck class, represents a deck object that has a size and is made up of a vector of card objects
// has a draw method, that returns the card on the top of the deck vector
class Deck {
    // private data member, represents deck's size
    int deck_size;
    
public:
    // public member data: vector of Card pointer objects
    vector<Card*> deck_vector;
    // deck_size accessor function
    void set_deck_size(int size);
    // deck_size mutator function
    int get_deck_size();
    // Deck default constructor
    Deck();
    // Deck constructor
    Deck(int size);
    // Deck copy constructor, performs deep copy
    Deck(const Deck&);
    // Deck destructor
    ~Deck();
    // stream insertion operator overloader function that calls a virtual print method to be overloaded
    friend ostream& operator << (ostream& output, const Deck &deck);
    // virtual print function that is overridden by all card subclasses
    virtual ostream& print(ostream& output) const;
    // assignment operator overloader, performs shallow copy
    virtual const Deck& operator=(const Deck& deck);
    // draw function, returns Card object by reference
    Card& draw();
};


class Hand {
    // private data member: int representing hand size
    int hand_size;
    
public:
    // public data member: vector of Card pointer objects
    vector<Card*> hand_vector;
    // hand_size accessor function
    int get_hand_size();
    // hand_size mutator function
    void set_hand_size(int size);
    // Hand default constructor
    Hand();
    // Hand constructor
    Hand(int size, Deck &deck);
    // Hand copy constructor, performs deep copy
    Hand(const Hand&);
    // Hand destructor
    ~Hand();
    // stream insertion operator overloader function that calls a virtual print method to be overloaded
    friend ostream& operator << (ostream& output, const Hand &hand);
    // virtual print function that is overridden by all card subclasses
    virtual ostream& print(ostream& output) const;
    // assignment operator overloader, performs shallow copy
    virtual const Hand& operator=(const Hand& hand);
}; 


class SpyCard : public Card {
public:
    // Spycard default constructor
    SpyCard();
    // Spycard copy constructor, performs deep copy
    SpyCard(const SpyCard&);
    // Spycard destructor
    ~SpyCard();
    // virtual print function that overrides the Card base function
    virtual ostream& print(ostream& output) const override;
    // virtual play function that overrides the Card base function
    virtual void play() override;
    // assignment operator overloader, performs shallow copy
    virtual const SpyCard& operator=(const SpyCard& spyCard);
};


class BombCard : public Card {
public:
    // Bombcard default constructor
    BombCard();
    // Bombcard copy constructor, performs deep copy
    BombCard(const BombCard&);
    // Bombcard destructor
    ~BombCard();
    // virtual print function that overrides the Card base function
    virtual ostream& print(ostream& output) const override;
    // virtual play function that overrides the Card base function
    virtual void play() override;
    // assignment operator overloader, performs shallow copy
    virtual const BombCard& operator=(const BombCard& bombCard);
};


class ReinforcementCard : public Card {
public:
    // ReinforcementCard deafult constructor
    ReinforcementCard();
    // ReinforcementCard copy constructor, performs deep copy
    ReinforcementCard(const ReinforcementCard&);
    // ReinforcementCard destructor
    ~ReinforcementCard();
    // virtual print function that overrides the Card base function
    virtual ostream& print(ostream& output) const override;
    // virtual play function that overrides the Card base function
    virtual void play() override;
    // assignment operator overloader, performs shallow copy
    virtual const ReinforcementCard& operator=(const ReinforcementCard& reinforcementCard);
};


class BlockadeCard : public Card {
public:
    // BlockadeCard deafult constructor
    BlockadeCard();
    // BlockadeCard copy constructor, performs deep copy
    BlockadeCard(const BlockadeCard&);
    // BlockadeCard destructor
    ~BlockadeCard();
    // virtual print function that overrides the Card base function
    virtual ostream& print(ostream& output) const override;
    // virtual play function that overrides the Card base function
    virtual void play() override;
    // assignment operator overloader, performs shallow copy
    virtual const BlockadeCard& operator=(const BlockadeCard& blockadeCard);
};


class AirliftCard : public Card {
public:
    // AirliftCard deafult constructor
    AirliftCard();
    // AirliftCard copy constructor, performs deep copy
    AirliftCard(const AirliftCard&);
    // AirliftCard destructor
    ~AirliftCard();
    // virtual print function that overrides the Card base function
    virtual ostream& print(ostream& output) const override;
    // virtual play function that overrides the Card base function
    virtual void play() override;
    // assignment operator overloader, performs shallow copy
    virtual const AirliftCard& operator=(const AirliftCard& airliftCard);
};


class DiplomacyCard : public Card {
public:
    // DiplomacyCard deafult constructor
    DiplomacyCard();
    // DiplomacyCard copy constructor, performs deep copy
    DiplomacyCard(const DiplomacyCard&);
    // DiplomacyCard destructor
    ~DiplomacyCard();
    // virtual print function that overrides the Card base function
    virtual ostream& print(ostream& output) const override;
    // virtual play function that overrides the Card base function
    virtual void play() override;
    // assignment operator overloader, performs shallow copy
    virtual const DiplomacyCard& operator=(const DiplomacyCard& diplomacyCard);
};   

#endif /* Cards_hpp */
