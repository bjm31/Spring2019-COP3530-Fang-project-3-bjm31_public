#include"deck.hpp"

Deck::Deck() {

	this->numberOfCardsInDeck = 0;
	this->top = new Card(0, nullptr, nullptr); //dummy node at bottom of deck
}

void Deck::MakeFullDeck() {
	
	for (int i = 0; i < NUMBER_OF_CARDS_IN_RACKO_DECK; ++i) {

		this->Push(++numberOfCardsInDeck);
	}

	Shuffle();
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

	int count = numberOfCardsInDeck * numberOfCardsInDeck;	//number of random insertions
	
	std::srand(std::time(nullptr));							//use current time as seed for random generator
	
	do {

		int rng = std::rand() % numberOfCardsInDeck;	//generate a random number between 0 and 59

		this->InsertAt(this->top, rng);					//inserts the top card at the random spot

		--count;

	} while (count != 0);
}

void Deck::InsertAt(Card* card, int index) {

	Card* temp = this->top;

	for (int i = 0; i < index; ++i) {

		temp = temp->GetNext();
	}
	
	if (card->GetPrev() != nullptr && card->GetNext() != nullptr) {

		if (card == this->top) {

			this->top->GetNext()->SetPrev(nullptr);

			this->top = card->GetNext();
		}

		else {

			card->GetNext()->SetPrev(card->GetPrev());

			card->GetPrev()->SetNext(card->GetNext());
		}
		
		card->SetNext(temp);

		card->SetPrev(temp->GetPrev());
		
		temp->SetPrev(card);
	}
}