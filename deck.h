//
//  deck.h
//  Poker
//
//  Created by Blake Sweet on 6/23/18.
//  Copyright © 2018 Blake. All rights reserved.
//

#ifndef deck_h
#define deck_h

#include "card.h"
#include "mainhelper.h"
using namespace std;

const int MAX_CARDS = 53;
const int MAX_HAND = 15;

class deck{
public:
    deck();
    void GetDeck ();
    int GetCard (int CardNumber, string CardSuit);
    void PrintDeck ();
    void PrintHand (card hand[MAX_HAND]);
    void PrintHand (card hand[MAX_HAND], string Sensor);
    void AddToHand (card hand[MAX_HAND], int card);
    void RemoveFromHand (card hand[MAX_HAND], int card);
    void ResetHand (card hand[]);
    bool UniqueHand(card hand[MAX_HAND], int NewCard);
    bool TestAce(card hand[]);
    bool TestAce(card card);
    
private:
    card CardList[MAX_CARDS];
};

#endif /* deck_h */
