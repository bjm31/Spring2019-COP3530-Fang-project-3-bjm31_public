#include"game.hpp"

Game::Game(std::vector<Player> players) {

	this->players = players;

	this->numberOfPlayers = players.size();

	this->currentPlayerTurn = 0;

	this->currentRound = 0;

	this->deck.MakeFullDeck();

	this->discard.Discard(deck.Draw());
}

void Game::DoNextTurn() {



}

bool Game::IsGameOver() {

	return false;
}

Player* Game::GetPlayer(int playerNumber) {

	return &this->players.at(--playerNumber);
}

int Game::ShowTopOfDiscardPile() {

	return this->discard.Peek();
}

Card* Game::DrawFromDeck() {

	if (this->deck.Peek() == 0) {

		/*move cards from discard pile to deck*/
		do {

			this->deck.Discard(this->discard.Draw());

		} while (this->discard.Peek() != 0);

		this->deck.Shuffle();

		this->discard.Discard(this->deck.Draw());
	}

	return this->deck.Draw();
}

void Game::Discard(Card* card) {

	this->discard.Discard(card);
}