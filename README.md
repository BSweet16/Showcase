# Resume
Last updated 10/30/19. <br/>
Linked In Profile: https://www.linkedin.com/in/blake-sweet-097741117/ <br/>

# Blackjack
I created this Blackjack game as a fun project for long car rides. <br/>
Please excuse the hairy code, there were little children in the car rides as well and they could be distracting at times. <br/>

The game begins by creating an object called a "Game" (G in the code for short hand). <br/>
The deck is created by generating a list of "Numbers" (Num in the code for short hand) of values 1-52 in which are then converted to a number 1-13 and stored with agiven "suit" into a "Card" object into the "Game".<br/>
The "Player" and "Dealer" hands are both given cards from this list until they are given cards that they do not yet have. <br/>
 *Note* - At the moment it is possible for a "Player" or "Dealer" to have a card that the other has, but they do not.<br/>
 Ex) The "Player" and the "Dealer" can both have an Ace of spades, however the "Player" can not have 2 Ace of spades<br/><br/>
  
The user is given the option to (H) Hit, (S) Stand, (P) Split until they are no longer allowed to do so by game rules. <br/>
The "Dealer" follows typical rules after the "Player" finishes taking their turn; "hitting" under 17 and "standing" when equal to or greater than 17. <br/>
The game will repeat until either the player runs out of money or chooses to quit after playing a hand.

Please report bugs to: ekalbteews 'at' gmail.com <br/>
Thank you for exploring and enjoy!
