// Card.h
// Card class structure

// Programmer: Charlie Sun
// 11/07/13

#ifndef CARD_H
#define CARD_H

#include <vector>
using std::vector;

// Each card has a integer value and a suit
struct ACard
{
	int Num;
	char Pic[4];
};

class Card
{
private:
	ACard Cards[52]; // 52 cards in a deck
	int NextCard;	// Returns index of next card
		
	int line; // Line number of picture
	void PrintLine(int [], int, ACard []); // Prints Line
	
public:
	Card();
	void ShuffleCard();	// Shuffles deck
	ACard GetCard();	// Returns next card

	void PrintDeck(); // Prints Deck
	void PrintCard(vector<ACard> &h); // Prints Card
	void CardAce(const char Pic[], int line);		// Print Ace
	void CardTwo(const char Pic[], int line);		// Print 2
	void CardThree(const char Pic[], int line);	// Print 3
	void CardFour(const char Pic[], int line);	// Print 4
	void CardFive(const char Pic[], int line);	// Print 5
	void CardSix(const char Pic[], int line);		// Print 6
	void CardSeven(const char Pic[], int line);	// Print 7
	void CardEight(const char Pic[], int line);	// Print 8
	void CardNine(const char Pic[], int line);	// Print 9
	void CardTen(const char Pic[], int line);		// Print 10
	void CardJack(const char Pic[], int line);	// Print Jack
	void CardQueen(const char Pic[], int line);	// Print Queen
	void CardKing(const char Pic[], int line);	// Print King
	void CardBlank(int line);
};

// Unicode for spade, club, heart, and diamond
const char spade[4] = "\xe2\x99\xa0";
const char club[4] = "\xe2\x99\xa3";
const char heart[4] = "\xe2\x99\xa5";
const char diamond[4] = "\xe2\x99\xa6";

#endif
