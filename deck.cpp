#include"deck.hpp"

#include<iostream>

Deck::Deck() {

	this->numberOfCardsInDeck = 0;
	this->top = new Card(); //dummy node
}

void Deck::MakeFullDeck() {
	
	for (int i = 1; i <= NUMBER_OF_CARDS_IN_RACKO_DECK; ++i) {

		this->Push(i);
	}

	//Shuffle();
}

void Deck::Push(int value) {

	if (this->top->GetValue() != -1) {
		
		this->top = new Card(value, this->top->GetPrev(), this->top);

		this->top->GetPrev()->SetNext(this->top);

		this->top->GetNext()->SetPrev(this->top);
	}

	else {

		this->top = new Card(value, this->top, nullptr);

		this->top->GetPrev()->SetNext(this->top);
	}

	++numberOfCardsInDeck;
}

void Deck::Discard(Card* card) {

	card->SetNext(this->top);

	this->top = card;
	
	++numberOfCardsInDeck;
}

Card* Deck::Draw() {

	Card* temp = this->top;
	
	if (numberOfCardsInDeck == 0) {

		return nullptr;
	}
	
	else if (numberOfCardsInDeck > 1) {

		this->top->GetPrev()->SetNext(this->top->GetNext());

		this->top->GetNext()->SetPrev(this->top->GetPrev());
	}

	this->top = temp->GetNext();
	
	temp->SetPrev(nullptr);
	
	temp->SetNext(nullptr);

	--numberOfCardsInDeck;

	return temp;
}

int Deck::Peek() {

	return this->top->GetValue();
}

/*
Shuffle works in that it swaps the top card and a 
random card as many times as the number of cards squared.
*/
void Deck::Shuffle() {

	int count = numberOfCardsInDeck * numberOfCardsInDeck;	//number of random swaps
	
	std::srand(std::time(nullptr));							//use current time as seed for random generator
	
	do {

		int rng = std::rand() % numberOfCardsInDeck + 1; //generate a random number between 1 and number of cards in the deck
		
		Card* swap = this->top;

		for (int i = 2; i < rng; ++i) {

			swap = swap->GetNext();
		}

		if (rng == numberOfCardsInDeck) {


		}

		Card* topPrev = this->top->GetPrev();

		Card* topNext = this->top->GetNext();

		this->top->GetPrev()->SetNext(swap);
		
		this->top->SetPrev(swap->GetPrev());
		
		this->top->SetNext(swap->GetNext());

		swap->GetPrev()->SetNext(this->top);
		
		swap->GetNext()->SetPrev(this->top);

		swap->SetPrev(topPrev);

		swap->SetNext(topNext);

		this->top = swap;

		--count;

	} while (count != 0);
}

void Deck::InsertAt(Card* card, int index) {

	Card* temp = this->top;

	for (int i = 0; i < index; ++i) {

		temp = temp->GetNext();
	}
	
	if (card == this->top) {

		this->top->GetNext()->SetPrev(this->top->GetPrev());

		this->top = this->top->GetNext();
	}

	else {

		card->GetNext()->SetPrev(card->GetPrev());

		card->GetPrev()->SetNext(card->GetNext());
	}
		
	card->SetNext(temp);

	card->SetPrev(temp->GetPrev());
		
	temp->SetPrev(card);
}