#include"game.hpp"

#include<iostream>

int main()
{
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
	}

	Game game = Game(players);

	for (int i = 0; i < players.size() * 10; ++i) {


	}

	return 0;
}