//  =================================================
//  ===================== Poker =====================
//  =================================================
//  main.cpp
//
//
//  Created by Blake Sweet on 6/23/18.
//  Copyright © 2018 Blake. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <time.h>
#include "card.h"
#include "deck.h"
#include "mainhelper.h"
using namespace std;

const int STARTING_BAL = 100;

bool UniqueCards(int a, int b, int c, int d){
    bool Answer = false;
    
    if(a != b && a != c && a != d && b != c && b != d && c != d)
    {Answer = true;}
    
    return Answer;
}

int Start(){
    int choice;
    helper H;
    
    H.Clr(); H.Clr(); // Start with fresh page (text at bottom)
    
    do{
        /* List Options */
        H.Clr();
        cout << "=== Welcome to the table === \n1: Play Game \n2: Print Deck \n3: Quit \n::=> ";
        cin >> choice;
        
        /* Make a Choice */
        switch(choice){
            case 1: break;
            case 2: {deck G; G.PrintDeck(); break;}// Load deck if you need it only
            case 3: {choice = -1; break;}
            default: {cout << "Invalid Option!";}
        }
        cout << "\n";
    }while(choice != 1 && choice != -1);
    
    return choice;
}


/* ====================================================================
   ====================================================================
   ========================= BLACKJACK GAME ===========================
   ====================================================================
   ==================================================================== */
int main() {
    /* Variables */
    int Bal = STARTING_BAL;
    int bet = 0;
    int c1, c2, c4, d1, d2; // Deal Random Cards to each player
    bool Continue = true;
    int PlayerSum = 0;
    int PlayerSecondSum = 0;
    int DealerSum;
    char temp;
    int NewCard;
    string Pause;
    int MenuChoice;
    bool SplitToggle = false;
    card PlayerHand[MAX_HAND];
    card PlayerSecondHand[MAX_HAND];
    card DealerHand[MAX_HAND];
    char HSS; // (HSS = Hit/ Stand/ Split)
    helper H; // Create the helper
    
    // Initialize ncurses library and seed
    srand(static_cast<unsigned int>(time(NULL)));  // seed
    
    /* Create the Cards */
    deck G;
    
    /* Menu */
    MenuChoice = Start();
    
    /* ================
            Play Game
       ================ */
    if (MenuChoice == 1){
    while (Bal > 0 && Continue == true){
        
        /* Player's Bet */
        bet = H.GetBet(Bal);
        
        /* Play */
        H.Clr();
        H.DisplayBanner("BlackJack");
        // H.DisplayMessage("Dealing Cards"); // Removed as a preference
        
        // Deal cards
        do{
            c1 = rand() % 52 + 1;
            c2 = rand() % 52 + 1;
            d1 = rand() % 52 + 1;
            d2 = rand() % 52 + 1;
        }while(!UniqueCards(c1, c2, d1, d2));
        c1 = 2;
        c2 = 24;
        G.AddToHand(PlayerHand, c1);
        G.AddToHand(PlayerHand, c2);
        G.AddToHand(DealerHand, d1);
        G.AddToHand(DealerHand, d2);
            
        // Show Player Hand
        H.DisplayPTotal(PlayerHand);
        G.PrintHand(PlayerHand);
        cout << '\n';
            
        // Show Dealer Hand
        H.DisplayDTotal(DealerHand);
        G.PrintHand(DealerHand, "???");
        
        // Let user decide what to do next
        if (H.GatherSum(DealerHand) == 21){ // If dealer already has 21, skip player
            HSS = 's';
        }
        else if (bet*2 <= Bal){ // Make sure bal has enough to split
            HSS = H.ShowOptions(PlayerHand);
        }
        else{
            HSS = H.ShowOptions(PlayerHand, PlayerHand);
        }
        
        // Play until split or stand
        while(HSS != 's' && HSS != 'S' && HSS != 'p' && HSS != 'P'){
            PlayerSum = H.PlayHand(HSS, PlayerSum, PlayerSecondSum, PlayerHand, PlayerSecondHand, DealerHand);
        }
        
        // Case: Split (Play both hands)
        if (HSS == 'p' || HSS == 'P'){
            // Toggle if there was a Split chosen
            H.SplitTrue(SplitToggle);
            
            // Reorganize original hand into 2 new hands with new cards
            G.AddToHand(PlayerSecondHand, c2);
            G.RemoveFromHand(PlayerHand, 1);
            do{
                c2 = rand() % 52 + 1;
                c4 = rand() % 52 + 1;
            }while(!G.UniqueHand(PlayerHand, c2) && G.UniqueHand(PlayerSecondHand, c4));
            G.AddToHand(PlayerHand, c2);
            G.AddToHand(PlayerSecondHand, c4);
        }
            
        // Get Dealer's Sum
        DealerSum = H.GatherSum(DealerHand);
            
        /* Get rest of Dealer's Cards*/
        if ((!SplitToggle && PlayerSum > 21) || (!SplitToggle && PlayerSum == 21)){
            // Used to skip if:
                // Player has already busted but only has one hand
                // Player has already hit blackjack with one hand
        }
        else if (PlayerSum < 21 || PlayerSecondSum < 21){ // If the player hasn't already busted or won
            if (DealerSum == 21){cout << "Dealer BlackJack...\n";}
            else{
                while(DealerSum < 17){ // Give dealer another card (under 17)
                    do{
                        NewCard = rand() % 52 + 1;
                    }while(!G.UniqueHand(DealerHand, NewCard));
                    G.AddToHand(DealerHand, NewCard);
                    
                    // Dealer's Total
                    DealerSum = H.GatherSum(DealerHand);
                }
            }
        }
            
        H.Clr();
        H.DisplayBanner("BlackJack");
        H.DisplayPTotal(PlayerHand);
        G.PrintHand(PlayerHand);
        if (SplitToggle){ // If there was a split show that hand
            H.DisplayPTotal(PlayerSecondHand);
            G.PrintHand(PlayerSecondHand);
        }
        H.DisplayFullDTotal(DealerHand);
        G.PrintHand(DealerHand);
        cout << '\n';
            
        /* Gather Sums Per Player */
        PlayerSum = H.GatherSum(PlayerHand);
        if (SplitToggle)
            PlayerSecondSum = H.GatherSum(PlayerSecondHand);
        DealerSum = H.GatherSum(DealerHand);
            
        // Analyze Player Sums
        if (SplitToggle){ cout << "Hand 1:" << '\n';}
        H.AnalyzeSum(Bal, bet, PlayerSum, DealerSum);
        if (SplitToggle){
            cout << "Hand 2:" << '\n';
            H.AnalyzeSum(Bal, bet, PlayerSecondSum, DealerSum);
        }
            
        /* Play Again? */
        if (Bal > 0){
            cout << "Would you like to play another hand? (Y/N): ";
            cin >> temp;
            if (temp == 'N' || temp == 'n'){
                Continue = false;
            }
            cout << '\n';
            
            // Reset all records
            H.SplitFalse(SplitToggle);
            G.ResetHand(PlayerHand);
            G.ResetHand(DealerHand);
            if (SplitToggle){
                G.ResetHand(PlayerSecondHand);
                H.SplitFalse(SplitToggle);
            }
            H.Clr(); H.Clr(); H.Clr();
        }
        else{
            H.DisplayMessage("You are out of money.");
        }
    } // Play
    }// If/While
    
    // Goodbye message if player chose to quit
    if (Bal > 0){
        H.GoodBye(Bal);
    }
    
    //system("pause");
    return 0;
    
}
