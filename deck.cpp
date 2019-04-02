#include"deck.hpp"

Deck::Deck() {

	this->numberOfCardsInDeck = 0;
	this->top = nullptr;
}

void Deck::MakeFullDeck() {
	
	for (int i = 0; i < NUMBER_OF_CARDS_IN_RACKO_DECK; ++i) {

		Push(++numberOfCardsInDeck);
	}

	this->Shuffle();
}

void Deck::Push(int value) {

	this->top = new Card(value, nullptr, this->top);
}

void Deck::Discard(Card* card) {

	this->Push(card->GetValue());
}

Card* Deck::Draw() {
	
	Card* temp = this->top;
	
	this->top = this->top->GetNext();
	this->top->SetPrev(nullptr);

	return temp;
}

int Deck::Peek() {

	return this->top->GetValue();
}

void Deck::Shuffle() {


}

void Deck::InsertAt(Card* card, int index) {

	Card* temp = this->top->GetNext();

	for (int i = 1; i <= index; ++i) {
	
		temp = temp->GetNext();
	}

	temp = card;
}
