#include"game.hpp"

Game::Game(std::vector<Player> players) {

	this->players = players;

	this->numberOfPlayers = players.size();

	this->currentPlayerTurn = 0;

	this->currentRound = 0;

	this->deck.MakeFullDeck();
}

void Game::DoNextTurn() {

	for (int i = 0; i < this->numberOfPlayers; ++i) {


	}

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

	if (this->deck.Draw() == nullptr) {

		deck = discard;

		this->deck.Shuffle();

		discard = Deck();

		this->discard.Discard(this->deck.Draw());
	}

	return this->deck.Draw();
}

void Game::Discard(Card* card) {

	this->discard.Discard(card);
}