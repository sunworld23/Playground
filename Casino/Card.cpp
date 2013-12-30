// Card.cpp
// Card class member functions

// Programmer: Charlie Sun
// 11/07/13

#include "Card.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

// Constructor
Card::Card()
{
	// Initialize Spades
	for(int i = 0; i < 13; i++)
	{
		Cards[i].Num = i + 1;
		for(int j = 0; j < 4; j++)
			Cards[i].Pic[j] = spade[j];
	}
	
	// Initialize Clubs
	for(int i = 13; i < 26; i++)
	{
		Cards[i].Num = i - 12;
		for(int j = 0; j < 4; j++)
			Cards[i].Pic[j] = club[j];
	}
		
	// Initialize Hearts
	for(int i = 26; i < 39; i++)
	{		
		Cards[i].Num = i - 25;
		for(int j = 0; j < 4; j++)
			Cards[i].Pic[j] = heart[j];
	}
	
	// Initialize Diamonds
	for(int i = 39; i < 52; i++)
	{
		Cards[i].Num = i - 38;
		for(int j = 0; j < 4; j++)
			Cards[i].Pic[j] = diamond[j];
	}
	
	NextCard = 0;
	srand(time(NULL));
}

// Shuffles deck
// Input: None
// Output: None
void Card::ShuffleCard()
{
	//ACard temp;
	//int pos1, pos2;
	
	/*
	for(int i = 0; i < 100000; i++)
	{		
		pos1 = rand() % 52;
		pos2 = rand() % 52;

		temp = Cards[pos1];
		Cards[pos1] = Cards[pos2];
		Cards[pos2] = temp;
	}
	*/
	ACard temp[52];
	ACard swap;
	int pos1;
	for(int i = 0; i < 10000; i++)
	{	
		for(int j = 0; j < 52; j = j + 2)
			temp[j] = Cards[j/2];
			
		for(int j = 1; j < 52; j = j + 2)
			temp[j] = Cards[j/2 + 26];
			
		for(int j = 0; j< 52; j++)
			Cards[j] = temp[j];
			
		pos1 = rand() % 52;
		swap = Cards[0];
		Cards[0] = Cards[pos1];
		Cards[pos1] = swap;
	}
	
	NextCard = 0;
}

// Retrieves card from top of deck
// Input: None
// Output: ACard type
ACard Card::GetCard()
{
	ACard temp = Cards[NextCard];
	NextCard++;
	return temp;
}

// Prints line by line
// Input: integer array of values, size of array, ACard class for suits
// Output: None
void Card::PrintLine(int value[], int size, ACard temp[])
{
	for(line = 1; line <= 11; line++)
		{
			for(int j = 0; j < size; j++)
			{
				switch(value[j])
				{
					case 1:
						CardAce(temp[j].Pic, line);
						break;
					case 2:
						CardTwo(temp[j].Pic, line);
						break;
					case 3:
						CardThree(temp[j].Pic, line);
						break;
					case 4:
						CardFour(temp[j].Pic, line);
						break;
					case 5:
						CardFive(temp[j].Pic, line);
						break;
					case 6:
						CardSix(temp[j].Pic, line);
						break;
					case 7:
						CardSeven(temp[j].Pic, line);
						break;
					case 8:
						CardEight(temp[j].Pic, line);
						break;
					case 9:
						CardNine(temp[j].Pic, line);
						break;
					case 10:
						CardTen(temp[j].Pic, line);
						break;
					case 11:
						CardJack(temp[j].Pic, line);
						break;
					case 12:
						CardQueen(temp[j].Pic, line);
						break;
					case 13:
						CardKing(temp[j].Pic, line);
						break;
					default:
						CardBlank(line);
				}
				cout << " ";
			}
			cout << endl;	
		}
}

// Prints the whole deck
// Input: None
// Output: None
void Card::PrintDeck()
{
	const int SIZE = 13;
	
	int value[SIZE];
	ACard temp[SIZE];
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			temp[j] = GetCard();
			value[j] = temp[j].Num;
		}
	
		PrintLine(value, SIZE, temp);
	}
	
	NextCard = 0;
}

// Prints hand from Poker class
// Input: Vector of type ACard
// Output: None
void Card::PrintCard(vector<ACard> &h)
{
	const int SIZE = h.size();
	
	ACard temp[SIZE];
	int value[SIZE];
	
	for(int j = 0; j < SIZE; j++)
	{
		temp[j] = h.at(j);
		value[j] = temp[j].Num;
	}
	
	PrintLine(value, SIZE, temp);
	
}

// The following 13 functions print 13 different cards
// Input: Suit and Line number
// Output: None
void Card::CardAce(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|" << "A" << setw(7) << "|";
			break;
		case 3:
			cout << "|" << setw(8) << "|";
			break;
		case 4:
			cout << "|" << setw(8) << "|";
			break;
		case 5:
			cout << "|" << setw(8) << "|";
			break;
		case 6:
			cout << "|" << setw(6) << Pic << setw(4) << "|";
			break;
		case 7:
			cout << "|" << setw(8) << "|";
			break;
		case 8:
			cout << "|" << setw(8) << "|";
			break;
		case 9:
			cout << "|" << setw(8) << "|";
			break;
		case 10:
			cout << "|" << setw(7) << "A" << "|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardTwo(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|" << "2" << setw(7) << "|";
			break;
		case 3:
			cout << "|" << setw(8) << "|";
			break;
		case 4:
			cout << "|" << setw(6) << Pic << setw(4) << "|";
			break;
		case 5:
			cout << "|" << setw(8) << "|";
			break;
		case 6:
			cout << "|" << setw(8) << "|";
			break;
		case 7:
			cout << "|" << setw(8) << "|";
			break;
		case 8:
			cout << "|" << setw(6) << Pic << setw(4) << "|";
			break;
		case 9:
			cout << "|" << setw(8) << "|";
			break;
		case 10:
			cout << "|" << setw(7) << "2" << "|";
			break;
		case 11:
			cout << "---------";
			break;
	}

}

void Card::CardThree(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|" << "3" << setw(7) << "|";
			break;
		case 3:
			cout << "|" << setw(6) << Pic << setw(4) << "|";
			break;
		case 4:
			cout << "|" << setw(8) << "|";
			break;
		case 5:
			cout << "|" << setw(8) << "|";
			break;
		case 6:
			cout << "|" << setw(6) << Pic << setw(4) << "|";
			break;
		case 7:
			cout << "|" << setw(8) << "|";
			break;
		case 8:
			cout << "|" << setw(8) << "|";
			break;
		case 9:
			cout << "|" << setw(6) << Pic << setw(4) << "|";
			break;
		case 10:
			cout << "|" << setw(7) << "3" << "|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardFour(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|" << "4" << setw(7) << "|";
			break;
		case 3:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 4:
			cout << "|" << setw(8) << "|";
			break;
		case 5:
			cout << "|" << setw(8) << "|";
			break;
		case 6:
			cout << "|" << setw(8) << "|";
			break;
		case 7:
			cout << "|" << setw(8) << "|";
			break;
		case 8:
			cout << "|" << setw(8) << "|";
			break;
		case 9:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 10:
			cout << "|" << setw(7) << "4" << "|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardFive(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|" << "5" << setw(7) << "|";
			break;
		case 3:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 4:
			cout << "|" << setw(8) << "|";
			break;
		case 5:
			cout << "|" << setw(8) << "|";
			break;
		case 6:
			cout << "|" << setw(6) << Pic << setw(4) << "|";
			break;
		case 7:
			cout << "|" << setw(8) << "|";
			break;
		case 8:
			cout << "|" << setw(8) << "|";
			break;
		case 9:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 10:
			cout << "|" << setw(7) << "5" << "|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardSix(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|" << "6" << setw(7) << "|";
			break;
		case 3:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 4:
			cout << "|" << setw(8) << "|";
			break;
		case 5:
			cout << "|" << setw(8) << "|";
			break;
		case 6:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 7:
			cout << "|" << setw(8) << "|";
			break;
		case 8:
			cout << "|" << setw(8) << "|";
			break;
		case 9:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 10:
			cout << "|" << setw(7) << "6" << "|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardSeven(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|" << "7" << setw(7) << "|";
			break;
		case 3:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 4:
			cout << "|" << setw(6) << Pic << setw(4) << "|";
			break;
		case 5:
			cout << "|" << setw(8) << "|";
			break;
		case 6:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 7:
			cout << "|" << setw(8) << "|";
			break;
		case 8:
			cout << "|" << setw(8) << "|";
			break;
		case 9:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 10:
			cout << "|" << setw(7) << "7" << "|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardEight(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|" << "8" << setw(7) << "|";
			break;
		case 3:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 4:
			cout << "|" << setw(6) << Pic << setw(4) << "|";
			break;
		case 5:
			cout << "|" << setw(8) << "|";
			break;
		case 6:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 7:
			cout << "|" << setw(8) << "|";
			break;
		case 8:
			cout << "|" << setw(6) << Pic << setw(4) << "|";
			break;
		case 9:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 10:
			cout << "|" << setw(7) << "8" << "|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardNine(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|" << "9" << setw(7) << "|";
			break;
		case 3:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 4:
			cout << "|" << setw(8) << "|";
			break;
		case 5:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 6:
			cout << "|" << setw(6) << Pic << setw(4) << "|";
			break;
		case 7:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 8:
			cout << "|" << setw(8) << "|";
			break;
		case 9:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 10:
			cout << "|" << setw(7) << "9" << "|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardTen(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|" << "10" << setw(6) << "|";
			break;
		case 3:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 4:
			cout << "|" << setw(6) << Pic << setw(4) << "|";
			break;
		case 5:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 6:
			cout << "|" << setw(8) << "|";
			break;
		case 7:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 8:
			cout << "|" << setw(6) << Pic << setw(4) << "|";
			break;
		case 9:
			cout << "|" << setw(4) << Pic << setw(6) << Pic << setw(2) << "|";
			break;
		case 10:
			cout << "|" << setw(7) << "10" << "|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardJack(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|" << Pic << "J" << setw(6) << "|";
			break;
		case 3:
			cout << "|" << setw(8) << "|";
			break;
		case 4:
			cout << "|" << setw(8) << "|";
			break;
		case 5:
			cout << "|" << setw(8) << "|";
			break;
		case 6:
			cout << "|" << setw(8) << "|";
			break;
		case 7:
			cout << "|" << setw(8) << "|";
			break;
		case 8:
			cout << "|" << setw(8) << "|";
			break;
		case 9:
			cout << "|" << setw(8) << "|";
			break;
		case 10:
			cout << "|" << setw(6) << "J" << Pic << "|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardQueen(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|" << Pic << "Q" << setw(6) << "|";
			break;
		case 3:
			cout << "|" << setw(8) << "|";
			break;
		case 4:
			cout << "|" << setw(8) << "|";
			break;
		case 5:
			cout << "|" << setw(8) << "|";
			break;
		case 6:
			cout << "|" << setw(8) << "|";
			break;
		case 7:
			cout << "|" << setw(8) << "|";
			break;
		case 8:
			cout << "|" << setw(8) << "|";
			break;
		case 9:
			cout << "|" << setw(8) << "|";
			break;
		case 10:
			cout << "|" << setw(6) << "Q" << Pic << "|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardKing(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|" << Pic << "K" << setw(6) << "|";
			break;
		case 3:
			cout << "|" << setw(8) << "|";
			break;
		case 4:
			cout << "|" << setw(8) << "|";
			break;
		case 5:
			cout << "|" << setw(8) << "|";
			break;
		case 6:
			cout << "|" << setw(8) << "|";
			break;
		case 7:
			cout << "|" << setw(8) << "|";
			break;
		case 8:
			cout << "|" << setw(8) << "|";
			break;
		case 9:
			cout << "|" << setw(8) << "|";
			break;
		case 10:
			cout << "|" << setw(6) << "K" << Pic << "|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardBlank(int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout << "|/ / / /|";
			break;
		case 3:
			cout << "| / / / |";
			break;
		case 4:
			cout << "|/ / / /|";
			break;
		case 5:
			cout << "| / / / |";
			break;
		case 6:
			cout << "|/ / / /|";
			break;
		case 7:
			cout << "| / / / |";
			break;
		case 8:
			cout << "|/ / / /|";
			break;
		case 9:
			cout << "| / / / |";
			break;
		case 10:
			cout << "|/ / / /|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}
