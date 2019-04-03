#include"game.hpp"

#include<iostream>

void test1() {

	std::vector<Player> players;

	Hand playerHand;

	players.push_back(Player("Bryan", Hand(), 0));

	Game game = Game(players);

	for (int i = 0; i < 10; ++i) {

		playerHand.AddToHand(game.DrawFromDeck());
	}

	game.GetPlayer(1)->SetHand(playerHand);

	std::cout << std::endl << game.GetPlayer(1)->ShowHand() << std::endl;
}

int main()
{

	test1();

	/*
	int numberOfPlayers = 0;

	std::string playerName;
	
	int isComputer = -1;

	std::vector<Player> players;
	
	std::cout << "Lets play Racko!\n";
	
	std::cout << "How many players? (including computer, max 4): ";
	
	std::cin >> numberOfPlayers;

	for (int i = 1; i <= numberOfPlayers; ++i) {

		std::cout << "Enter player " << i << "'s name: ";
	
		std::cin >> playerName;
		
		std::cout << "Is this a computer? (1 = yes, 0 = no): ";
		
		std::cin >> isComputer;
		
		Hand playerHand;
		
		for (int j = 0; j < 10; ++j) {
			
			playerHand.AddToHand(game.deck.Draw());
		}

		players.push_back(playerName, Hand(), isComputer);
	}
	
	for (int i = 0; i < players.size() * 10; ++i) {


	}
	*/
	return 0;
}