// BlackJack.cpp
// BlackJack class member functions

// Programmer: Charlie Sun
// 11/21/13

#include "BlackJack.h"
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

// Constructor
BlackJack::BlackJack()
{
	handSum = 0;
	dealerSum = 0;
	handAces = 0;
	dealerAces = 0;
	insurance = 0;
}

// Sets the current balance
// Input: None
// Output: None
void BlackJack::setCash()
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
void BlackJack::setBet()
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
void BlackJack::setWinnings(int amount)
{
	float temp;
	
	cout << "Your initial balance was: $" << cash << endl;
	switch(amount)
	{
		case 1:
			temp = float(bet) * 1.5;
			cash += temp;
			cout << "Your current balance is: $" << cash << endl;
			cout << "You win: $" << int(temp) << endl; 
			break;
		case 2:
			cash += bet;
			cout << "Your current balance is: $" << cash << endl;
			cout << "You win: $" << bet << endl; 
			break;
		case 3:
			temp =  float(bet) * .5;
			cash += temp;
			cout << "Your current balance is: $" << cash << endl;
			cout << "You win: $" << int(temp) << endl;
			break;
		case 4:
			temp = float(bet) * 1.5;
			cash -= temp;
			cout << "Your current balance is: $" << cash << endl;
			cout << "You lose: $" << int(temp) << endl;
			break;
		case 5:
			temp =  float(bet) * .5;
			cash -= temp;
			cout << "Your current balance is: $" << cash << endl;
			cout << "You lose: $" << int(temp) << endl;
			break;
		case 6:
			cash -= bet;
			cout << "Your current balance is: $" << cash << endl;
			cout << "You lose: $" << bet << endl; 
			break;
		}
}

// Clears hand
// Input: None
// Output: None
void BlackJack::reset()
{
	hand.clear();
	dealer.clear();
	handSum = 0;
	dealerSum = 0;
	handAces = 0;
	dealerAces = 0;
	insurance = 0;
}

// Makes sure you have enough cash to continue playing
// Input: None
// Output: Boolean value
bool BlackJack::check()
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

// Gets 2 cards
// Input: None
// Output: None
void BlackJack::setHand()
{
	ACard temp;
	for(int i = 0; i < 2; i++)
	{
		temp = GetCard();
		setHandSum(temp);
		hand.push_back(temp);
		temp = GetCard();
		setDealerSum(temp);
		dealer.push_back(temp);
	}
	first = dealer[0];
	dealer[0].Num = 0;	
	
	// Testing
	/*
	dealer[0].Num = 3;
	dealer[1].Num = 1;
	dealerSum = 14;
	dealerAces = 1;
	*/
	
	cout << "Dealer" << endl;
	PrintCard(dealer);
	
	cout << endl;
	cout << "You" << endl;
	PrintCard(hand);
}

// Deals a card
// Input: None
// Output: Integer
int BlackJack::hit()
{
	if((hand[0].Num == 1 && hand[1].Num >= 10) || (hand[1].Num == 1 && hand[0].Num >= 10))
		return 1; 
	
	ACard temp;
	bool hit = 0;

	cout << endl;
	if(dealer[1].Num == 1)
	{
		cout << "Would you like to buy insurance (1 - yes, 0 - no)? ";
		cin >> insurance;
	}
	do
	{
		if(handSum > 21 && handAces > 0)
		{
			handSum -= 10;
			handAces--;
		}
		
		cout << "Your current hand is " << handSum << endl;
		cout << "Do you want to hit (1 - yes, 0 - no)? ";
		cin >> hit;
		
		if(hit)
		{
			temp = GetCard();
			setHandSum(temp);
			hand.push_back(temp);
			
			PrintCard(hand);
			
			if(handSum > 21)
			{
				if(handAces > 0)
				{
					handSum -= 10;
					handAces--;
				}
				else
				{
					cout << handSum << ". Bust" << endl;
					return 0;
				}
			}
		}
	} while(hit);
	
	if((dealer[0].Num == 1 && dealer[1].Num >= 10) || (dealer[1].Num == 1 && dealer[0].Num >= 10))
	{
		cout << endl << endl;
		cout << "Dealer" << endl;
		PrintCard(dealer);
		if(insurance)
			return 6;
		else
			return 4;
	}

	hit = 1;
	dealer[0] = first;
	cout << endl << endl;
	cout << "Dealer" << endl;
	while(hit)
	{
		if(dealerSum < 17)
		{
			temp = GetCard();
			setDealerSum(temp);
			dealer.push_back(temp);
			
			if(dealerSum > 21)
			{
				if(dealerAces > 0)
				{
					dealerSum -= 10;
					dealerAces--;
				}
				else
				{
					PrintCard(dealer);
					cout << "Dealer's hand is " << dealerSum << ". Dealer busts" << endl;
					return (2 + insurance);
				}
			}
		}
		else
		{
			if(dealerSum > 21 && dealerAces > 0)
			{
				dealerSum -= 10;
				dealerAces--;
			}
			else
				hit = 0;
		}
	}
	
	PrintCard(dealer);
	cout << "Dealer's hand is " << dealerSum << ". " << endl;
	
	if (handSum > dealerSum)
		return (2 + insurance);
	else
		return (4 + insurance);
}

// Adds card value to sum
// Input: ACard
// Output: None
void BlackJack::setHandSum(ACard temp)
{
	if(temp.Num > 10)
		handSum += 10;
	else if(temp.Num == 1)
	{
		handSum += 11;
		handAces++;
	}
	else
		handSum += temp.Num;
}

void BlackJack::setDealerSum(ACard temp)
{
	if(temp.Num > 10)
		dealerSum += 10;
	else if(temp.Num == 1)
	{
		dealerSum += 11;
		dealerAces++;
	}
	else
		dealerSum += temp.Num;
}
