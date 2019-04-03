#include"hand.hpp"
#include"card.hpp"

#include<string>

class Player {

public:
	Player();
	Player(std::string name, Hand hand, bool isComputer);
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