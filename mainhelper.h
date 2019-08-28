//
//  mainhelper.h
//  Poker
//
//  Created by Blake Sweet on 6/27/18.
//  Copyright © 2018 Blake. All rights reserved.
//

#ifndef mainhelper_h
#define mainhelper_h

#include <iostream>
#include <iomanip>
#include "deck.h"
#include "card.h"
using namespace std;

class helper{
public:
    // Message utility
    void Clr();
    void DisplayMessage(string Message);
    void DisplayBanner(string Message);
    
    void GoodBye(int UserBal);
    int AddSum(int UserSum, card UserHand[]);
    
    char ShowOptions(card hand[]);
    char ShowOptions(card hand[], card secondhand[]);
    
    void SplitFalse (bool& SplitToggle);
    void SplitTrue (bool& SplitToggle);
    void DisplayDTotal(card hand[]);
    void DisplayPTotal(card hand[]);
    void DisplayPTotal(card hand[], card secondhand[]);
    void DisplayFullDTotal(card hand[]);
    void AnalyzeSum(int& Bal, int bet, int PlayerSum, int DealerSum);
    
    int GetBet(int PlayerBal);
    int GatherSum(card hand[]);
    int PlayHand(char& PlayerChoice, int PlayerSum, int PlayerSecondSum, card PlayerHand[], card PlayerSecondHand[], card DealerHand[]);
    int PlayHandSP(int handcounter, char& PlayerChoice, int PlayerSum, int PlayerSecondSum, card PlayerHand[], card PlayerSecondHand[], card DealerHand[]); // Play hand after split
    
    // Input Gathering
    // Logic
    
private:
};

#endif /* mainhelper_h */
