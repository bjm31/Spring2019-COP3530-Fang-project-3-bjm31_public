#include"hand.hpp"

Hand::Hand() {

	this->lowestCard = new Card(0, nullptr, nullptr); //dummy node
}

void Hand::AddToHand(Card* card) {

	this->lowestCard->SetPrev(card);

	card->SetNext(lowestCard);
	
	card->SetPrev(nullptr);
	
	this->lowestCard = card;
}

Card* Hand::SwapOutCard(Card* card, int position) {
	
	Card* temp = this->lowestCard;

	for (int i = 2; i <= position; ++i) {

		temp = temp->GetNext();
	} 

	return temp;
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

	} while (temp->GetValue() != 0);

	return output;
}

Card* Hand::GetLowestCard() {

	return this->lowestCard;
}