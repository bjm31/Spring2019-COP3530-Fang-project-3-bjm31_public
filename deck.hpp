#ifndef DECK_HPP
#define DECK_HPP

#include"card.hpp"

#include <cstdlib>
#include <ctime>

#include<iostream>

class Deck {

public:
	Deck();
	void MakeFullDeck();
	void Push(int value);
	void Discard(Card* card);
	Card* Draw();
	int Peek();
	void Shuffle();
	void InsertAt(Card* card, int index);

private:
	Card* top;
	const int NUMBER_OF_CARDS_IN_RACKO_DECK = 60;
	int numberOfCardsInDeck;
};

#endif