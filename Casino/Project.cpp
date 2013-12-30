// Project.cpp
// Main function

// Programmer: Charlie Sun
// 11/07/13

#include <iostream>
#include <iomanip>
#include <vector>
#include "Card.h"
#include "Poker.h"
#include "BlackJack.h"
using namespace std;

int main()
{
	Poker p;
	BlackJack b;
	char play;
	char again;
	int amount = 0;
	
	cout << "Welcome to the Casino!" << endl;
	cout << "Do you want to play poker (p) or Black Jack (b)? ";
	cin >> play;
	
	if(play == 'p')
		p.setCash();
	else
		b.setCash();
	
	do
	{
		if(play == 'p')
		{
			p.Test();

			p.ShuffleCard();
			p.setBet();
			
			cout << endl;
			p.setHand();
			p.reDraw();
			cout << endl;
			p.setHand();

			switch(p.determineHand())
			{
				case 1:
					cout << "Pair of Jacks or better" << endl;
					amount = 1;
					break;
				case 2:
					cout << "Two pair" << endl;
					amount = 2;
					break;
				case 3:
					cout << "Triple!" << endl;
					amount = 4;
					break;
				case 4:
					cout << "Straight!" << endl;
					amount = 6;
					break;
				case 5:
					cout << "Flush!" << endl;
					amount = 8;
					break;
				case 6:
					cout << "Full House!!" << endl;
					amount = 10;
					break;
				case 7:
					cout << "Four of a Kind!!" << endl;
					amount = 20;
					break;
				case 8:
					cout << "Straight Flush!!!" << endl;
					amount = 100;
					break;
				case 9:
					cout << "*********************" << endl;
					cout << "** ROYAL FLUSH!!!! **" << endl;
					cout << "*********************" << endl;
					amount = 1000;
					break;
				default:
					cout << "Sorry. You lose." << endl;
					amount = -1;
			}

			p.setWinnings(amount);
			cout << "Do you want to play again (y,n)? ";
			cin >> again;
		
			if(again != 'n')
			{
				if(p.check())
					again = 'n';
				else
					cout << endl << endl;
			}
			
			p.reset();
		}
		else
		{
			b.ShuffleCard();
			b.setBet();
			
			b.setHand();
			switch(b.hit())
			{
				case 1:
					cout << "BLACKJACK!!!" << endl;
					amount = 1;
					break;
				case 2:
					cout << "You win!" << endl;
					amount = 2;
					break;
				case 3:
					cout << "You win! minus insurance" << endl;
					amount = 3;
					break;
				case 5:
					cout << "Sorry. You lose. And minus insurance" << endl;
					amount = 4;
					break;
				case 6:
					cout << "Returned bet minus insurance" << endl;
					amount = 5;
					break;
				default:
					cout << "Sorry. You lose." << endl;
					amount = 6;
			}
			
			b.setWinnings(amount);
			cout << "Do you want to play again (y,n)? ";
			cin >> again;
		
			if(again != 'n')
			{
				if(b.check())
					again = 'n';
				else
					cout << endl << endl;
			}
			
			b.reset();
		}

	} while(again != 'n');
	
	cout << "Have a nice day!" << endl;
	return 0;
}
