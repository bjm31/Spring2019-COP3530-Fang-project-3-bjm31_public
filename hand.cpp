#include"hand.hpp"

Hand::Hand() {

	this->lowestCard = new Card(); //dummy node
}

void Hand::AddToHand(Card* card) {

	if (this->lowestCard->GetValue() != -1) {

		card->SetPrev(this->lowestCard->GetPrev());

		card->SetNext(this->lowestCard);

		this->lowestCard->GetPrev()->SetNext(card);

		this->lowestCard->SetPrev(card);
	}

	else {

		card->SetPrev(this->lowestCard);

		card->SetNext(nullptr);
	}
	
	this->lowestCard = card;
}

Card* Hand::SwapOutCard(Card* card, int position) {

	Card* swap = this->lowestCard;

	for (int i = 2; i <= position; ++i) {

		swap = swap->GetNext();
	}

	if (position == 10) {
		
		swap->GetPrev()->SetNext(card);

		card->SetPrev(swap->GetPrev());

		swap->SetPrev(nullptr);

		return swap;
	}

	swap->GetPrev()->SetNext(card);
	
	swap->GetNext()->SetPrev(card);

	card->SetPrev(swap->GetPrev());

	card->SetNext(swap->GetNext());

	swap->SetPrev(nullptr);

	swap->SetNext(nullptr);

	if (swap == this->lowestCard) {

		this->lowestCard = card;
	}

	return swap;
}

bool Hand::HasRacko() {

	Card* temp = GetLowestCard();

	bool check = true;

	for (int i = 1; i < 9; ++i) {

		if (temp->GetValue() > temp->GetNext()->GetValue()) {

			check = false;

			break;
		}

		temp = temp->GetNext();
	}

	return check;
}

std::string Hand::ShowHand() {

	std::string output = "";
	
	std::string spaces = "";

	Card* temp = this->lowestCard;

	int i = 0;

	do {

		output += std::to_string(++i) + ":";

		/*creates the string of spaces per card position and card value*/
		for (int j = 0; j < temp->GetValue(); ++j) {

			spaces += " ";
		}
		
		output += spaces;					//adds spaces string to output

		output += std::to_string(temp->GetValue()) + "\n";
		
		spaces = "";						//reset number of spaces for next pass

		temp = temp->GetNext();				//get the next card

	} while (temp != nullptr);

	return output;
}

Card* Hand::GetLowestCard() {

	return this->lowestCard;
}
