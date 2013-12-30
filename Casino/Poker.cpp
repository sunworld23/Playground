// Poker.cpp
// Poker class member functions

// Programmer: Charlie Sun
// 11/14/13

#include "Poker.h"
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

// Constructor
Poker::Poker()
{
	// PrintDeck();
}

// For testing purposes
void Poker::Test()
{
	int num;
	cout << "Enter 1 for pair of jacks or better" << endl;
	cout << "Enter 2 for two pair" << endl;
	cout << "Enter 3 for triple" << endl;
	cout << "Enter 4 for straight" << endl;
	cout << "Enter 5 for flush" << endl;
	cout << "Enter 6 for full house" << endl;
	cout << "Enter 7 for four of a kind" << endl;
	cout << "Enter 8 for straight flush" << endl;
	cout << "Enter 9 for royal flush" << endl;
	cin >> num;
	
	hand.resize(5);
	
	switch(num)
	{
		case 1:
			for(int i = 0; i < 5; i++)
			{
				hand[i].Num = 2*i + 2;		
				strcpy(hand[i].Pic, spade);
			}
			hand[2].Num = 11;
			hand[3].Num = 11;	
			hand[4].Num = 12;
			strcpy(hand[0].Pic, heart);
			break;
		case 2:
			for(int i = 0; i < 5; i++)
			{
				hand[i].Num = 2*i + 1;		
				strcpy(hand[i].Pic, spade);
			}
			hand[1].Num = hand[0].Num;
			hand[3].Num = hand[4].Num;
			strcpy(hand[0].Pic, heart);
			break;
		case 3:
			for(int i = 0; i < 5; i++)
			{
				hand[i].Num = 2*i + 1;		
				strcpy(hand[i].Pic, spade);
			}
			hand[1].Num = hand[0].Num;
			hand[2].Num = hand[0].Num;
			strcpy(hand[0].Pic, heart);
			break;
		case 4:
			for(int i = 1; i < 5; i++)
			{
				hand[i].Num = i+9;		
				strcpy(hand[i].Pic, spade);
			}
			hand[0].Num = 1;
			strcpy(hand[0].Pic, heart);
			break;
		case 5:
			for(int i = 0; i < 5; i++)
			{
				hand[i].Num = 2*i + 1;		
				strcpy(hand[i].Pic, spade);
			}
			break;
		case 6:
			for(int i = 0; i < 5; i++)
			{
				strcpy(hand[i].Pic, spade);
			}
			hand[0].Num = 1;
			hand[1].Num = hand[0].Num;
			hand[2].Num = hand[0].Num;
			hand[3].Num = 2;
			hand[4].Num = 2;
			strcpy(hand[0].Pic, heart);
			break;
		case 7:
			for(int i = 0; i < 5; i++)
			{
				hand[i].Num = 2*i + 1;		
				strcpy(hand[i].Pic, spade);
			}
			hand[1].Num = hand[0].Num;
			hand[2].Num = hand[0].Num;
			hand[3].Num = hand[0].Num;
			strcpy(hand[0].Pic, heart);
			break;
		case 8:
			for(int i = 0; i < 5; i++)
			{
				hand[i].Num = i+1;		
				strcpy(hand[i].Pic, spade);
			}
			break;
		case 9:
			for(int i = 1; i < 5; i++)
			{
				hand[i].Num = i+9;		
				strcpy(hand[i].Pic, spade);
			}
			hand[0].Num = 1;
			strcpy(hand[0].Pic, spade);
			break;
		default:
			for(int i = 0; i < 5; i++)
			{
				hand[i].Num = 2*i + 2;		
				strcpy(hand[i].Pic, spade);
			}
			strcpy(hand[0].Pic, heart);
	}
}

// Sets the current balance
// Input: None
// Output: None
void Poker::setCash()
{
	do
	{
		cout << "Please enter an amount of money to play: ";
		cin >> cash;
		
		// Validate input
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(5000,'\n');
			cash = 0;
			cout << "Not a valid amount." << endl << endl;	
		}
		else if (cash == 0)
			cout << "You can't play without cash" << endl << endl;
		else if (cash < 0)
		{
			cout << "Not a valid amount." << endl << endl;
			cash = 0;
		}
		
	} while(cash == 0);
}

// Retrieves bet
// Input: None
// Output: None
void Poker::setBet()
{
	do
	{
		cout << "How much do you want to bet? ";
		cin >> bet;
		// Validate input
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(5000,'\n');
			bet = 0;
			cout << "Not a valid amount." << endl << endl;	
		}
		else if (bet > cash)
		{
			cout << "Bet cannot exceed how much you have." << endl << endl;	
			bet = 0;
		}
		else if (bet == 0)
			cout << "You must bet something." << endl << endl;
		else if (bet < 0)
		{
			cout << "Not a valid amount." << endl << endl;
			bet = 0;
		}
	} while(bet == 0);
}

// Calculates winnings
// Input: None
// Output: None
void Poker::setWinnings(int amount)
{
	cout << "Your initial balance was: $" << cash << endl;
	cash = cash + bet * amount;
	cout << "Your current balance is: $" << cash << endl;
	if(amount == -1)
		cout << "You lose: $" << bet << endl;
	else
		cout << "You win: $" << bet * amount << endl;
}

// Clears hand
// Input: None
// Output: None
void Poker::reset()
{
	hand.clear();
}

// Makes sure you have enough cash to continue playing
// Input: None
// Output: Boolean value
bool Poker::check()
{
	bool stop;
	
	if(cash <= 0)
	{
		stop = true;
		cout << "You are out of money" << endl;
	}
	else
		stop = false;
	
	return stop;
}

// Gets 5 cards from deck
// Input: None
// Output: None
void Poker::setHand()
{
	if(hand.size() == 0)
	{
		for(int i = 0; i < 5; i++)
			hand.push_back(GetCard());
	}

	sortHand();
	PrintCard(hand);
}

// Sorts cards
// Input: None
// Output: None
void Poker::sortHand()
{
	ACard temp;
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(hand[j].Num > hand[j+1].Num)
			{
				temp = hand[j];
				hand[j] = hand[j+1];
				hand[j+1] = temp;
			}
		}
	}
}

// Redraws cards
// Input: None
// Output: None
void Poker::reDraw()
{
	bool choice;
	for(int i = 0; i < 5; i++)
	{
		if(hand[i].Num == 11)
			cout << "J";
		else if(hand[i].Num == 12)
			cout << "Q";
		else if(hand[i].Num == 13)
			cout << "K";
		else if(hand[i].Num == 1)
			cout << "A";
		else
			cout << hand[i].Num;
		cout << hand[i].Pic << ": Hold (0) or Redraw (1)? ";
		cin >> choice;
		
		if(choice == true)
			hand.at(i) = GetCard();		
	}
}

int Poker::determineHand()
{
	// Check straight flush and royal flush
	// If not a straight, it will return just flush
	char suit[4];
	strcpy(suit, hand[0].Pic);
	bool flush = true;
	bool straight = true;
	for (int i = 0; i < 5; i++)
	{
		if(strcmp(suit,hand[i].Pic))
			flush = false;
	}
	for (int i = 0; i < 4; i++)
	{
		if(hand[i].Num != hand[i + 1].Num - 1)
			straight = false;
	}
	if(flush)
	{
		if(straight)
			return 8;
		else
		{
			if(Ace())
				return 9;
			else
				return 5;
		}
	}
	if(straight)
		return 4;
	if(Ace())
		return 4;
		
	// Check for 4 of a kind
	int rank = hand[0].Num;
	bool same1 = true;
	for (int i = 0; i < 4; i++)
	{
		if(rank != hand[i].Num)
			same1 = false;
	}
	rank = hand[1].Num;
	bool same2 = true;
	for (int i = 1; i < 5; i++)
	{
		if(rank != hand[i].Num)
			same2 = false;
	}
	if(same1 || same2)
		return 7;
	
	// Check for full house
	// If only 3 of a kind found returns that instead
	rank = hand[0].Num;
	bool trips = true;
	for (int i = 0; i < 3; i++)
	{
		if(rank != hand[i].Num)
			trips = false;
	}
	if(trips)
	{
		if(hand[3].Num == hand[4].Num)
			return 6;
		else
			return 3;
	}
	rank = hand[2].Num;
	trips = true;
	for (int i = 2; i < 5; i++)
	{
		if(rank != hand[i].Num)
			trips = false;
	}
	if(trips)
	{
		if(hand[0].Num == hand[1].Num)
			return 6;
		else
			return 3;
	}
	rank = hand[1].Num;
	trips = true;
	for (int i = 1; i < 4; i++)
	{
		if(rank != hand[i].Num)
			trips = false;
	}
	if(trips)
		return 3;
	
	// Check for two pair
	for(int i = 0; i < 4; i++)
	{
		if(hand[i].Num == hand[i+1].Num)
		{
			if(i == 0)
			{
				if(hand[2].Num == hand[3].Num)
					return 2;
				else if(hand[3].Num == hand[4].Num)
					return 2;
			}
			else if(i == 1)
			{
				if(hand[3].Num == hand[4].Num)
					return 2;
			}
		}
	}

	// Check for Pair of Jacks or better
	for(int i = 0; i < 4; i++)
	{
		if(hand[i].Num >= 11 && hand[i].Num == hand[i+1].Num)
			return 1;
	}
	
	return 0;
}

// Determines a special case for a stright with Ace high
// Input: None
// Output: Boolean value
bool Poker::Ace()
{
	bool straight = true;
	for (int i = 1; i < 4; i++)
	{
		if(hand[i].Num != hand[i + 1].Num - 1)
			straight = false;
	}
	if(hand[0].Num != 1)
		straight = false;
	return straight;
}
