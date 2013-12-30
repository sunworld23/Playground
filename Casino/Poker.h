// Poker.h
// Poker class structure

// Programmer: Charlie Sun
// 11/14/13

#ifndef POKER_H
#define POKER_H

#include "Card.h"
#include <vector>
using std::vector;

class Poker: public Card
{
private:
	int cash;		// Current balance
	int bet;		// Current bet
	vector<ACard> hand; // Poker hand
	
	void sortHand(); // Sorts poker hand
	
	bool Ace();	// Check for Ace special cases

public:
	Poker();		// Constructor
	
	void setCash();		// Enters the starting balance
	void setBet();		// Enters the current bet
	void setWinnings(int); // Calculates the winnings
	
	void reset();		// Resets hand	
	bool check();		// Checks balance
	void setHand();		// Gets a poker hand
	void reDraw();		// Redraws cards
	int determineHand(); // Determines the hand
	
	void Test();	// For testing purposes
};

#endif
