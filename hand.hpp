#include"card.hpp"

#include<string>

class Hand {

public:
	Hand();
	void AddToHand(Card* card);
	Card* SwapOutCard(Card* card, int position);
	bool HasRacko();
	std::string ShowHand();
	Card* GetLowestCard();

private:
	Card* lowestCard;
};