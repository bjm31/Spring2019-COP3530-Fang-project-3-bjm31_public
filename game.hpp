#include"deck.hpp"
#include"player.hpp"

#include<vector>

class Game {

public:
	Game(std::vector<Player> players);
	void DoNextTurn();
	bool IsGameOver();
	Player* GetPlayer(int playerNumber);
	int ShowTopOfDiscardPile();
	Card* DrawFromDeck();
	void Discard(Card* card);

private:
	std::vector<Player> players;
	int numberOfPlayers;
	int currentPlayerTurn;
	int currentRound;
	Deck deck;
	Deck discard;
};