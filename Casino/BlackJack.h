// BlackJack.h
// BlackJack class structure

// Programmer: Charlie Sun
// 11/21/13

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Card.h"
#include <vector>
using std::vector;

class BlackJack: public Card
{
private:
	int cash;		// Current balance
	int bet;		// Current bet
	vector<ACard> hand; // BlackJack hand
	vector<ACard> dealer; // Dealer's hand
	ACard first;	// Holds on to dealer's first card
	int handSum;	// Sum of values of cards
	int dealerSum;	// Sum of values of dealer's cards
	int handAces; // Keeps track of aces
	int dealerAces;
	bool insurance;

public:
	BlackJack();		// Constructor
	
	void setCash();		// Enters the starting balance
	void setBet();		// Enters the current bet
	void setWinnings(int); // Calculates the winnings
	
	void reset();		// Resets hand	
	bool check();		// Checks balance
	void setHand();		// Gets a BlackJack hand
	int hit();	// Gives you a card
	
	void setHandSum(ACard); 	// Calculates sum
	void setDealerSum(ACard); // Calculates dealer sum
};

#endif
