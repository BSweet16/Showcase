//
//  card.h
//  Poker
//
//  Created by Blake Sweet on 6/23/18.
//  Copyright © 2018 Blake. All rights reserved.
//

#ifndef card_h
#define card_h
#include <string>
using namespace std;

class card{
    public:
        string GetSuit();
        int GetNum();
        int GetAltNum();
        void SetSuit(string New);
        void SetNum(int New);
        void SetAltNum(int New);
        int CardValue();
    
        void PrintCardsInDeck();
        void PrintCard();
    
    private:
        string Suit = "";
        int Num = 0;
        int AltNum = 0;
};

#endif /* card_h */
