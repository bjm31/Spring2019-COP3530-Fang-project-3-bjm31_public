#include"player.hpp"

Player::Player() {

	this->playerName = "";
	this->hand = Hand();
	this->isComputer = false;
}

Player::Player(std::string name, Hand hand, bool isComputer) {
	
	this->playerName = name;
	this->hand = hand;
	this->isComputer = isComputer;
}

void Player::SetName(std::string name) {

	this->playerName = name;
}

void Player::SetHand(Hand hand) {

	this->hand = hand;
}

void Player::SetIsComputer(bool isComputer) {

	this->isComputer = isComputer;
}

std::string Player::TurnPrompt() {

	std::string output = "";

	return output + this->playerName + "'s turn";
}

std::string Player::ShowHand() {

	return this->hand.ShowHand();
}

Card* Player::SwapOutCard(Card* card, int position) {

	return this->hand.SwapOutCard(card, position);
}

bool Player::HasRacko() {

	return this->hand.HasRacko();
}

std::string Player::GetName() {

	return this->playerName;
}

bool Player::IsComputer() {

	return false;
}

std::string Player::MakeChoice(int discardOption) {

	return "";
}

int Player::ComputerChooseSlot(int cardValue) {

	return -1;
}