//
//  card.cpp
//  Poker
//
//  Created by Blake Sweet on 6/23/18.
//  Copyright © 2018 Blake. All rights reserved.
//

#include "card.h"
#include <iostream>
#include <iomanip>

int card::GetNum(){
    return Num;
}

string card::GetSuit(){
    return Suit;
}

int card::GetAltNum(){
    return AltNum;
}

void card::SetSuit(string New){
    Suit = New;
}

void card::SetNum(int New){
    Num = New;
}

void card::SetAltNum(int New){
    AltNum = New;
}

int card::CardValue(){
    if (GetNum() == 11 || GetNum() == 12 || GetNum() == 13){
        return 10;
    }
    else{
        return GetNum();
    }
}

void card::PrintCardsInDeck(){
    int CardNum = GetNum();
    
    if (CardNum == 1 || CardNum == 14 || CardNum == 27 || CardNum == 40){
        cout << right << setw(5) << "Ace" << " " << left << setw(10) << GetSuit();
    }
    else if (CardNum == 11 || CardNum == 24 || CardNum == 37 || CardNum == 50){
        cout << right << setw(5) << "Jack" << " " << left << setw(10) << GetSuit();
    }
    else if (CardNum == 12 || CardNum == 25 || CardNum == 38 || CardNum == 51){
        cout << right << setw(5) << "Queen" << " " << left << setw(10) << GetSuit();
    }
    else if (CardNum == 13 || CardNum == 26 || CardNum == 39 || CardNum == 52){
        cout << right << setw(5) << "King" << " " << left << setw(10) << GetSuit();
    }
    else{
        cout << right << setw(5) << GetNum() << " " << left << setw(10) << GetSuit();
    }
}

void card::PrintCard(){
    int CardNum = GetNum();
    string Name = "";
    
    if (CardNum == 1 || CardNum == 14 || CardNum == 27 || CardNum == 40){
        Name = "Ace";
    }
    else if (CardNum == 11 || CardNum == 24 || CardNum == 37 || CardNum == 50){
        Name = "Jack";
    }
    else if (CardNum == 12 || CardNum == 25 || CardNum == 38 || CardNum == 51){
        Name = "Queen";
    }
    else if (CardNum == 13 || CardNum == 26 || CardNum == 39 || CardNum == 52){
        Name = "King";
    }
    else{
        Name = GetNum();
    }
    
    if (CardNum == 1 || CardNum == 14 || CardNum == 27 || CardNum == 40 || CardNum == 11 || CardNum == 24 || CardNum == 37 || CardNum == 50 || CardNum == 12 || CardNum == 25 || CardNum == 38 || CardNum == 51 || CardNum == 13 || CardNum == 26 || CardNum == 39 || CardNum == 52){
        
        if (GetSuit() == "♣" || GetSuit() == "♠"){ // Added extra space for club alignment
            cout << "\t\t" << setw(12) << "+------+" << '\n'
                 << "\t\t" << setw(1) <<  "|" << left << setw(6) << Name << setw(1) << "|" << '\n'
                 << "\t\t" << setw(1) <<  "|" << left << setw(7) << GetSuit() << setw(1) << " |" << '\n'
                 << "\t\t" << setw(12) << "+------+" << '\n';
        }
        else{
            cout << "\t\t" << setw(12) << "+------+" << '\n'
                 << "\t\t" << setw(1) <<  "|" << left << setw(6) << Name << setw(1) << "|" << '\n'
                 << "\t\t" << setw(1) <<  "|" << left << setw(7) << GetSuit() << setw(1) << "|" << '\n'
                 << "\t\t" << setw(12) << "+------+" << '\n';
        }
    }
    else{
        if (GetSuit() == "♣" || GetSuit() == "♠"){ // Added extra space for club alignment
            cout << "\t\t" << setw(12) << "+---+" << '\n'
                 << "\t\t" << setw(1) << "|" << left << setw(3) << GetNum() << setw(1) << "|" << '\n'
                 << "\t\t" << setw(1) << "|" << left << setw(4) << GetSuit() << setw(1) << " |" << '\n'
                 << "\t\t" << setw(12) << "+---+" << '\n';
        }
        else{
            cout << "\t\t" << setw(12) << "+---+" << '\n'
                 << "\t\t" << setw(1) << "|" << left << setw(3) << GetNum() << setw(1) << "|" << '\n'
                 << "\t\t" << setw(1) << "|" << left << setw(4) << GetSuit() << setw(1) << "|" << '\n'
                 << "\t\t" << setw(12) << "+---+" << '\n';
        }
    }
}
