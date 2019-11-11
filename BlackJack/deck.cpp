//
//  deck.cpp
//  Poker
//
//  Created by Blake Sweet on 6/23/18.
//  Copyright © 2018 Blake. All rights reserved.
//

#include "deck.h"
#include <iostream>

deck::deck(){
    GetDeck();
}

void deck::GetDeck(){
    for (int i = 1; i <= 52; i++){
        card NewCard; // Create new card
        
        // Assign Suit
        if (i>=1 && i<14){NewCard.SetNum(i);NewCard.SetSuit("♡");}
        else if (i>=14 && i<27){NewCard.SetNum(i-13);NewCard.SetSuit("♣");}
        else if (i>=27 && i<40){NewCard.SetNum(i-26);NewCard.SetSuit("♢");}
        else if (i>=40 && i<=52){NewCard.SetNum(i-39);NewCard.SetSuit("♠");}
        
        if (NewCard.GetNum() == 1){NewCard.SetAltNum(11);} // Aces have alternate card value
        CardList[i] = NewCard; // Add Card to the list
    }
}

int deck::GetCard (int CardNumber, string CardSuit){
    for (int i = 0; i < MAX_CARDS; i++){
        if (CardNumber == CardList[i].GetNum() && CardSuit == CardList[i].GetSuit()){
            return i;
        }
    }
    return -1; // Error
}

void deck::PrintDeck(){
    for (int i = 1; i < MAX_CARDS/4 + 1; i++){
        CardList[i].PrintCardsInDeck();
        CardList[i+13].PrintCardsInDeck();
        CardList[i+26].PrintCardsInDeck();
        CardList[i+39].PrintCardsInDeck();
        cout << '\n';
    }
}

void deck::PrintHand(card hand[MAX_HAND]){
    for (int i = 0; i < MAX_HAND; i++){
        if (hand[i].GetNum() != 0){
            hand[i].PrintCard();
        }
    }
    cout << '\n';
}

void deck::PrintHand (card hand[MAX_HAND], string Sensor){
    hand[0].PrintCard();
    cout << "\t\t" << setw(12) << "+---+" << '\n'
         << "\t\t" << setw(1) << "|" << left << setw(3) << Sensor << setw(1) << "|" << '\n'
         << "\t\t" << setw(1) << "|" << left << setw(3) << Sensor << setw(1) << "|" << '\n'
         << "\t\t" << setw(12) << "+---+" << '\n';
    cout << '\n';
}

void deck::AddToHand(card hand[MAX_HAND], int card){
    for (int i = 0; i < MAX_HAND; i++){
        if (hand[i].GetNum() == 0){ // Find an empty spot
            hand[i] = CardList[card];
            return;
        }
    }
    cout << "Your hand is full." << '\n';
}

void deck::RemoveFromHand (card hand[MAX_HAND], int index){
    hand[index].SetNum(0); // Reset card
    hand[index].SetAltNum(0);
    hand[index].SetSuit("");
    
    for (int i = index; i < MAX_HAND-index; i++){ // Push all cards forward
        hand[i] = hand[i+1];
        
        if (i != MAX_HAND){
            hand[i+1].SetNum(0); // Reset next card
            hand[i+1].SetAltNum(0);
            hand[i+1].SetSuit("");
        }
    }
}

void deck::ResetHand(card hand[]){
    for (int i = 0; i < MAX_HAND; i++){
        hand[i].SetNum(0);
        hand[i].SetAltNum(0);
        hand[i].SetSuit("");
    }
}

bool deck::UniqueHand(card hand[MAX_HAND], int NewCard){
    bool Answer = false;
    
    for (int i = 0; i < MAX_HAND; i++){ // Search hand for matching new card
        if (hand[i].GetNum() == CardList[NewCard].GetNum() && hand[i].GetSuit() == CardList[NewCard].GetSuit()){
            return false;
        }
        else{
            Answer = true;
        }
        
    }
    
    return Answer;
}

bool deck::TestAce(card hand[]){
    for (int i = 0; i < MAX_HAND; i++){
        // If card is an Ace
        if(hand[i].GetNum() == CardList[1].GetNum()
           || hand[i].GetNum() == CardList[14].GetNum()
           || hand[i].GetNum() == CardList[27].GetNum()
           || hand[i].GetNum() == CardList[40].GetNum()){
            return true;
        }
    }
    return false;
}

bool deck::TestAce(card card){
    if(card.GetNum() == CardList[1].GetNum()
       || card.GetNum() == CardList[14].GetNum()
       || card.GetNum() == CardList[27].GetNum()
       || card.GetNum() == CardList[40].GetNum()){
        return true;
    }
    else{
        return false;
    }
}
