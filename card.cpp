#include"card.hpp"

Card::Card(int value, Card* prev = nullptr, Card* next = nullptr) {
	
	SetValue(value);
	SetPrev(prev);
	SetNext(next);
}

void Card::SetNext(Card* next) {

	this->next = next;
}

void Card::SetPrev(Card* prev) {

	this->prev = prev;
}

int Card::GetValue() {

	return this->value;
}

Card* Card::GetNext() {
	
	return this->next;
}

Card* Card::GetPrev() {

	return this->prev;
}
