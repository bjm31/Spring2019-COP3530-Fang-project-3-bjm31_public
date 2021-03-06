#ifndef PLAYER_HPP
#define PLAYER_HPP

#include"hand.hpp"

#include<string>

class Player {

public:
	Player();
	Player(std::string name, Hand hand = Hand(), bool isComputer = false);
	void SetName(std::string name);
	void SetHand(Hand hand);
	void SetIsComputer(bool isComputer);
	std::string TurnPrompt();
	std::string ShowHand();
	Card* SwapOutCard(Card* card, int position);
	bool HasRacko();
	std::string GetName();
	bool IsComputer();
	std::string MakeChoice(int discardOption);
	int ComputerChooseSlot(int cardValue);

private:
	std::string playerName;
	Hand hand;
	bool isComputer;
};

#endif
