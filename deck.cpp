#include"deck.hpp"

Deck::Deck() {

	this->numberOfCardsInDeck = 0;
	this->top = new Card(0, nullptr, nullptr); //dummy node at bottom of deck
}

void Deck::MakeFullDeck() {
	
	for (int i = 0; i < NUMBER_OF_CARDS_IN_RACKO_DECK; ++i) {

		this->Push(++numberOfCardsInDeck);
	}

	this->Shuffle();
}

void Deck::Push(int value) {

	this->top = new Card(value, nullptr, this->top);
}

void Deck::Discard(Card* card) {

	card->SetNext(this->top);
	
	card->SetPrev(nullptr);

	this->top = card;
	
	++numberOfCardsInDeck;

}

Card* Deck::Draw() {
	
	Card* temp = this->top;
	
	this->top = this->top->GetNext();
	this->top->SetPrev(nullptr);

	--numberOfCardsInDeck;

	return temp;
}

int Deck::Peek() {

	return this->top->GetValue();
}

void Deck::Shuffle() {

	std::srand(std::time(nullptr)); //use current time as seed for random generator
	int rng = std::rand() % 10 + 12;

	std::cout << rng << endl;

	for (int i = 0; i < numberOfCardsInDeck / 10; ++i) {



	}
}

void Deck::InsertAt(Card* card, int index) {

	Card* temp = this->top;

	for (int i = 1; i <= index; ++i) {
	
		temp = temp->GetNext();
	}

	temp = card;
}