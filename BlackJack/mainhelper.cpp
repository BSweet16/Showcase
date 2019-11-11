//
//  mainhelper.cpp
//  Poker
//
//  Created by Blake Sweet on 6/27/18.
//  Copyright © 2018 Blake. All rights reserved.
//

#include "mainhelper.h"

void helper::Clr(){ // Improv Clear Screen
    cout << "\n\n\n\n\n\n\n\n\n\n";
}

void helper::DisplayMessage(string Message){
    cout << setw(30) << "*******************************" << '\n'
    << setw(2) << '\t' << left << setw(25) << Message << setw(1) << '\n'
    << setw(30) << "*******************************" << '\n';
    cout << '\n';
}

void helper::DisplayBanner(string Message){
    cout << "\t\t\t\t" << setw(30) << left << "**************************" << '\n'
    << "\t\t\t\t" << setw(1) << "*\t\t" << left << setw(17) << Message << setw(1) << '*' << setw(1) << '\n'
    << "\t\t\t\t" << setw(30) << "**************************" << '\n';
    cout << '\n';
}

void helper::GoodBye(int UserBal){
    cout << setw(30) << "==============================\n" <<
    setw(30) << " You escaped with   \n" <<
    setw(1) << right << "$" << setw(29) << left << UserBal << '\n' <<
    setw(30) << "==============================\n";
}

int helper::AddSum(int UserSum, card UserHand[]){
    UserSum = 0;
    for (int i = 0; i < MAX_HAND; i++){
        if (UserHand[i].GetNum()>10){
            UserSum += 10;
        }
        else{
            UserSum += UserHand[i].GetNum();
        }
    }
    return UserSum;
}

void helper::SplitTrue(bool& Switch){
    Switch = true;
}

void helper::SplitFalse(bool& Switch){
    Switch = false;
}

char helper::ShowOptions(card hand[]){
    char Answer;
    
    if (hand[0].GetNum() == hand[1].GetNum()){
        do{
            cout << "Which would you like to do?\n(H) Hit\n(S) Stand\n(P) Split\n::=>";
            cin >> Answer;
            if (cin.fail()){ // Verify input
                cin.clear();
                cin.ignore(numeric_limits<int>::max(),'\n');
            }
            if (Answer != 'h' && Answer != 'H' && Answer != 's' && Answer != 'S' && Answer != 'p' && Answer != 'P'){
                cout << "Invalid choice. Please double check available options." << '\n';
            }
            cout << '\n';
        }while(Answer != 'h' && Answer != 'H' && Answer != 's' && Answer != 'S' && Answer != 'p' && Answer != 'P');
    }
    else{
        do{
            cout << "Which would you like to do?\n(H) Hit\n(S) Stand\n::=>";
            cin >> Answer;
            if (cin.fail()){ // Verify input
                cin.clear();
                cin.ignore(numeric_limits<int>::max(),'\n');
            }
            if (Answer != 'h' && Answer != 'H' && Answer != 's' && Answer != 'S'){
                cout << "Invalid choice. Please double check available options." << '\n';
            }
            cout << '\n';
        }while(Answer != 'h' && Answer != 'H' && Answer != 's' && Answer != 'S');
    }
    return Answer;
}

// Show options after split
char helper::ShowOptions(card hand[], card secondhand[]){
    char Answer;
    
    cout << "Which would you like to do?\n(H) Hit\n(S) Stand\n::=>";
    cin >> Answer;
    if (cin.fail()){ // Verify input
        cin.clear();
        cin.ignore(numeric_limits<int>::max(),'\n');
    }
    cout << '\n';
    
    return Answer;
}

void helper::DisplayDTotal(card hand[]){
    deck G;

    if (G.TestAce(hand[1]) && hand[1].GetAltNum() <= 21){
        cout << "Dealer's Hand: (" << hand[0].CardValue() << "/" << hand[1].GetAltNum() << ")\n"; // Dealer hand
    }
    else{
        cout << "Dealer's Hand: (" << hand[0].CardValue() << ")\n"; // Dealer hand
    }
}

void helper::DisplayPTotal(card hand[]){
    deck G;
    
    if (G.TestAce(hand) && AddSum(0, hand)+10 <= 21){
        cout << "Player's Hand: (" << AddSum(0, hand) << "/" << AddSum(0, hand)+10 << ")\n"; // Player hand
    }
    else{
        cout << "Player's Hand: (" << AddSum(0, hand) << ")\n"; // Player hand
    }
}

void helper::DisplayPTotal(card hand[], card secondhand[]){
    deck G;
    
    // Test if hands have ACEs
    if((G.TestAce(hand) && AddSum(0, hand)+10 <= 21) && // Both hand ACE
       (G.TestAce(secondhand) && AddSum(0, secondhand)+10 <= 21)){
        cout << "Player's Hand: (" << AddSum(0, hand) << "/" << AddSum(0, hand)+10 << ")\n";
        cout << "Player's Second Hand: (" << AddSum(0, secondhand) << "/" << AddSum(0, secondhand)+10 << ")\n";
    }
    else if (G.TestAce(hand) && AddSum(0, hand)+10 <= 21){ // First hand only ACE
        cout << "Player's Hand: (" << AddSum(0, hand) << "/" << AddSum(0, hand)+10 << ")\n";
        cout << "Player's Second Hand: (" << AddSum(0, secondhand) << ")\n";
    }
    else if (G.TestAce(secondhand) && AddSum(0, secondhand)+10 <= 21){ // Second hand only ACE
        cout << "Player's Hand: (" << AddSum(0, hand) << ")\n";
        cout << "Player's Second Hand: (" << AddSum(0, secondhand) << "/" << AddSum(0, secondhand)+10 << ")\n";
    }
    else{ // Neither hand ACE
        cout << "Player's Hand: (" << AddSum(0, hand) << ")\n";
        cout << "Player's Second Hand: (" << AddSum(0, secondhand) << ")\n";

    }
}

void helper::DisplayFullDTotal(card hand[]){
    deck G;
    
    if (G.TestAce(hand) && AddSum(0, hand)+10 <= 21){
        cout << "Dealer's Hand: (" << AddSum(0, hand) << "/" << AddSum(0, hand)+10 << ")\n"; // Dealer hand
    }
    else{
        cout << "Dealer's Hand: (" << AddSum(0, hand) << ")\n"; // Dealer hand
    }
}

int helper::GetBet(int PlayerBal){
    int bet = 0;
    
    do {
        cout << "Balance: $" << PlayerBal << '\n';
        cout << "Place a bet: $";
        cin >> bet;
        if (cin.fail()){ // Verify input
            cin.clear();
            cin.ignore(numeric_limits<int>::max(),'\n');
        }
        
        if (bet > PlayerBal){
            cout << "You don't have that much to bet!" << '\n' << '\n';
        }
        else if (bet <= 0){
            cout << "You must bet something.\n\n";
        }
    }while(bet <= 0 || bet > PlayerBal);
    
    return bet;
}

int helper::GatherSum(card hand[]){
    int Sum;
    deck G;
    
    if (G.TestAce(hand) && AddSum(0, hand)+10 <= 21){
        Sum = AddSum(0, hand)+10;
    }
    else{
        Sum = AddSum(0, hand);
    }
    return Sum;
}

int helper::PlayHand(char& PlayerChoice, int PlayerSum, int PlayerSecondSum, card PlayerHand[], card PlayerSecondHand[], card DealerHand[]){
    
    // Define Variables
    int NewCard;
    char SwitchedChoice;
    deck G;
    
    switch(PlayerChoice){
        case 'h': case 'H': { // Hit
            
            // Add a new card to the hand
            do{
                NewCard = rand() % 52 + 1;
            }while(!G.UniqueHand(PlayerHand, NewCard));
            
            G.AddToHand(PlayerHand, NewCard);
            Clr();
            DisplayBanner("BlackJack");
            DisplayPTotal(PlayerHand);
            G.PrintHand(PlayerHand);
            DisplayDTotal(DealerHand);
            G.PrintHand(DealerHand, "???");
            cout << '\n';
            
            // Check if player busted
            PlayerSum = GatherSum(PlayerHand);
            
            if (PlayerSum > 21){
                cout << "** BUST **\n";
            }
            else if (PlayerSum == 21){
                DisplayMessage("BlackJack!");
            }
            break;
            
        }
        case 'p': case 'P': { // Split
            SwitchedChoice = ShowOptions(PlayerHand, PlayerHand);
            
            while (SwitchedChoice != 's' && SwitchedChoice != 'S'){
                switch(SwitchedChoice){ // Play first hand
                    case 'h': case 'H':// Hit
                    {
                        do{
                            NewCard = rand() % 52 + 1;
                        }while(!G.UniqueHand(PlayerHand, NewCard));
                        G.AddToHand(PlayerHand, NewCard);
                        Clr();
                        DisplayBanner("BlackJack");
                        DisplayPTotal(PlayerHand);
                        G.PrintHand(PlayerHand);
                        DisplayDTotal(DealerHand);
                        G.PrintHand(DealerHand, "???");
                        cout << '\n';
                        
                        // Check if player busted
                        PlayerSum = GatherSum(PlayerHand);
                        
                        if (PlayerSum > 21){
                            cout << "** BUST **\n";
                        }
                        else if (PlayerSum == 21){
                            DisplayMessage("BlackJack!");
                        }
                        break;
                        
                    }
                    case 's': // Stand
                    case 'S': {break;}
                }
            }
        }
        case 's': case 'S': {break;} // Stand
    }
    
    // Ask again unless busted
    if (PlayerSum >= 21){
        PlayerChoice = 's';
    }
    else{
        PlayerChoice = ShowOptions(PlayerHand);
    }
    
    return PlayerSum;
}

void helper::AnalyzeSum(int& Bal, int bet, int PlayerSum, int DealerSum){
    if (PlayerSum == DealerSum && PlayerSum < 21){
        DisplayMessage("Draw"); cout << "\n\n";
    }
    else if ((PlayerSum > DealerSum && PlayerSum <= 21) ||
             (PlayerSum == DealerSum && PlayerSum == 21)){ // Player wins
        DisplayMessage("WINNER WINNER, CHICKEN DINNER!"); cout << "\n\n";
        Bal += bet;
        cout << "New Balance: $" << Bal << "\n\n";
    }
    else if ((PlayerSum < DealerSum && DealerSum <= 21) || PlayerSum > 21){ // Dealer Wins
        DisplayMessage("The house won this one.."); cout << "\n\n";
        Bal -= bet;
        cout << "New Balance: $" << Bal << "\n\n";
    }
    else if (DealerSum > 21){
        DisplayMessage("Dealer Bust!"); cout << "\n\n";
        Bal += bet;
        cout << "New Balance: $" << Bal << "\n\n";
    }
    else{
        cout << "?? ERROR ??\n\n";
    }
}
