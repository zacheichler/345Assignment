//  Cards.cpp
//  Part 5
//  Emilie Mines & Zach Eichler.

#include "Cards.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// CARD FUNCTIONS

// Card constructor
Card::Card() {
    num_of_cards++;
}

// Card copy constructor
Card::Card(const Card &card2) {
    
}

// Card deconstructor
Card::~Card() {
    num_of_cards--;
}

// static member function accessor for num_of_cards
int Card::get_num_of_cards() {
    return num_of_cards;
}

// instantiates static variable num_of_cards
int Card::num_of_cards = 0;

// virtual base play method to be overloaded depending on subclass of Card
void Card::play() {
}

// implements a stream insertion operator that calls a virtual print method to be overloaded
// uses pass by reference on Card objects
ostream& operator << (ostream& output, const Card &card) {
    return card.print(output);
}

// outputs a string describing the Card, depending on the subclass of Card
ostream& Card::print(ostream& output) const {
    output << "\nCard PRINT";
    return output;
}

// assignment operator overloader, performs shallow copy
const Card& Card::operator=(const Card& card) {
    
    return *this;
}



// DECK FUNCTIONS

// Deck default constructor
Deck::Deck(){
}

// Deck constructor, takes deck size as an arg and prints deck vector
Deck::Deck(int size) {
    this->set_deck_size(size);
    cout << "Deck created\n";
    int random = rand() % 6 +1;
    
    for (int i = 0; i < size; i++)
    {
        random = rand() % 6 +1;
        
        // switch statement adds randomly generated cards to the deck
        switch(random)
        {
            case 1:
            {
                deck_vector.push_back(new SpyCard());
                break;
            }
            case 2:
            {
                deck_vector.push_back(new BombCard());
                break;
            }
            case 3:
            {
                deck_vector.push_back(new ReinforcementCard());
                break;
            }
            case 4:
            {
                deck_vector.push_back(new BlockadeCard());
                break;
            }
            case 5:
            {
                deck_vector.push_back(new AirliftCard());
                break;
            }
            case 6:
            {
                deck_vector.push_back(new DiplomacyCard());
                break;
            }
        }
        deck_size++;
    }
    // prints deck vector
    cout << *this << endl;
}

// Deck copy constructor, performs deep copy
Deck::Deck(const Deck &deck) :
deck_size(deck.deck_size),
deck_vector(deck.deck_vector) {
}

// Deck deconstructor
Deck::~Deck() {
}

// deck_size accessor function
int Deck::get_deck_size() {
    return deck_size;
}

// deck_size mutator function
void Deck::set_deck_size(int size) {
    this->deck_size = size;
}

// draw function draws a card from top of deck vector of Card pointer objects, returns a card object by reference
Card& Deck::draw() {
    Card *drawn_card = deck_vector.back();
    deck_vector.pop_back();
    deck_size--;
    return *drawn_card;
}

// stream insertion operator overloader function that calls a virtual print method to be overloaded
ostream& operator << (ostream& output, const Deck &deck) {
    return deck.print(output);
}

// virtual print function that is overridden by all card subclasses
ostream& Deck::print(ostream& output) const {
    output << "\nDECK VECTOR PRINT:\n";
    // prints vector of cards
    for (int i = 0; i < deck_vector.size(); i++) {
        // calls the appropriate print funciton, passes card object by pointer
        cout << *deck_vector[i] << endl;
    }
    return output;
}

// assignment operator overloader, performs shallow copy
const Deck& Deck::operator=(const Deck& deck) {
    deck_size = deck.deck_size;
    deck_vector = deck.deck_vector;
    return *this;
}




// HAND FUNCTIONS

// Hand default constructor
Hand::Hand() {
    
}

// Hand constructor, takes int size and a deck object as parameters
Hand::Hand(int size, Deck &deck) {
    // sets number of cards in hand
    this->set_hand_size(size);
    cout << "\nHand created of size " << this->get_hand_size() << endl;
    
    // draws number of cards in hand from deck
    for (int i = 0; i < size; i++) {
        Card& drawn = deck.draw();
        hand_vector.push_back(&drawn);
    }
    
    // prints hand vector
    cout << *this << endl;
}

// Hand copy constructor, performs deep copy
Hand::Hand(const Hand &hand) :
hand_size(hand.hand_size),
hand_vector(hand.hand_vector) {
}

// Hand deconstructor
Hand::~Hand() {
}

// stream insertion operator overloader function that calls a virtual print method to be overloaded
ostream& operator << (ostream& output, const Hand &hand) {
    return hand.print(output);
}

// virtual print function that is overridden by all card subclasses
ostream& Hand::print(ostream& output) const {
    output << "\nHAND VECTOR PRINT:\n";
    // prints vector of cards
    for (int i = 0; i < hand_vector.size(); i++) {
        // calls the appropriate print funciton, passes card object by pointer
        cout << *hand_vector[i] << endl;
    }
    return output;
}

// hand_size accessor function
int Hand::get_hand_size() {
    return hand_size;
}

// hand_size mutator function
void Hand::set_hand_size(int size) {
    this->hand_size = size;
}

// assignment operator overloader, performs shallow copy
const Hand& Hand::operator=(const Hand& hand) {
    hand_size = hand.hand_size;
    hand_vector = hand.hand_vector;
    return *this;
}


// SPYCARD FUNCTIONS

// SpyCard Constructor
 SpyCard::SpyCard() {
    cout << "Spy Card created!\n";
}

// SpyCard copy constructor
SpyCard::SpyCard(const SpyCard &spyCard) {
    
}

// SpyCard Destructor
SpyCard::~SpyCard(){
}

// overrides Card's print method
ostream& SpyCard::print(ostream& output) const {
    output << "Spy Card ";
    return output;
}

// overrides Card's play method
void SpyCard::play() {
    cout << "Spy card is played!\n";
}

// assignment operator overloader, performs shallow copy
const SpyCard& SpyCard::operator=(const SpyCard& spyCard) {
    
    return *this;
}


// BOMBCARD FUNCTIONS

// BombCard Constructor
BombCard::BombCard() {
    cout << "Bomb Card created!\n";
}

// BombCard copy constructor
BombCard::BombCard(const BombCard &bombCard) {
    
}

// BombCard Destructor
BombCard::~BombCard(){
}

// overrides Card's print method
ostream& BombCard::print(ostream& output) const {
    output << "Bomb Card ";
    return output;
}

// overrides Card's play method
void BombCard::play() {
    cout << "Bomb card is played!\n";
}

// assignment operator overloader, performs shallow copy
const BombCard& BombCard::operator=(const BombCard& bombCard) {
    
    return *this;
}


// REINFORCEMENT CARD FUNCTIONS

// Reinforcement Card Constructor
ReinforcementCard::ReinforcementCard() {
    cout << "Reinforcement Card created!\n";
}

// ReinforcementCard copy constructor
ReinforcementCard::ReinforcementCard(const ReinforcementCard &reinforcementCard) {
    
}

// ReinforcementCard Destructor
ReinforcementCard::~ReinforcementCard(){
}

// overrides Card's print method
ostream& ReinforcementCard::print(ostream& output) const {
    output << "Reinforcement Card ";
    return output;
}

// overrides Card's play method
void ReinforcementCard::play() {
    cout << "Reinforcement card is played!\n";
}

// assignment operator overloader, performs shallow copy
const ReinforcementCard& ReinforcementCard::operator=(const ReinforcementCard& reinforcementCard) {
    
    return *this;
}


// BLOCKADE CARD FUNCTIONS

// Blockade Card Constructor
BlockadeCard::BlockadeCard() {
    cout << "Blockade Card created!\n";
}

// BlockadeCard copy constructor
BlockadeCard::BlockadeCard(const BlockadeCard &blockadeCard) {
    
}

// BlockadeCard Destructor
BlockadeCard::~BlockadeCard(){
}

// overrides Card's print method
ostream& BlockadeCard::print(ostream& output) const {
    output << "Blockade Card ";
    return output;
}

// overrides Card's play method
void BlockadeCard::play() {
    cout << "Blockade card is played!\n";
}

// assignment operator overloader, performs shallow copy
const BlockadeCard& BlockadeCard::operator=(const BlockadeCard& blockadeCard) {
    
    return *this;
}


// AIRLIFT CARD FUNCTIONS

// Airlift Card Constructor
AirliftCard::AirliftCard() {
    cout << "Airlift Card created!\n";
}

// AirliftCard copy constructor
AirliftCard::AirliftCard(const AirliftCard &airliftCard) {
    
}

// AirliftCard Destructor
AirliftCard::~AirliftCard(){
}

// overrides Card's print method
ostream& AirliftCard::print(ostream& output) const {
    output << "Airlift Card ";
    return output;
}

// overrides Card's play method
void AirliftCard::play() {
    cout << "Airlift card is played!\n";
}

// assignment operator overloader, performs shallow copy
const AirliftCard& AirliftCard::operator=(const AirliftCard& airliftCard) {
    
    return *this;
}


// DIPLOMACY CARD FUNCTIONS

// Diplomacy Card constructor
DiplomacyCard::DiplomacyCard() {
    cout << "Diplomacy Card created!\n";
}

// DiplomacyCard copy constructor
DiplomacyCard::DiplomacyCard(const DiplomacyCard &diplomacyCard) {
    
}

// DiplomacyCard Destructor
DiplomacyCard::~DiplomacyCard(){
}

// overrides Card's print method
ostream& DiplomacyCard::print(ostream& output) const {
    output << "Diplomacy Card ";
    return output;
}

// overrides Card's play method
void DiplomacyCard::play() {
    cout << "Diplomacy card is played!\n";
}

// assignment operator overloader, performs shallow copy
const DiplomacyCard& DiplomacyCard::operator=(const DiplomacyCard& diplomacyCard) {
    
    return *this;
}
