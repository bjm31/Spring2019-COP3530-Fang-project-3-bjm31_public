#define CATCH_CONFIG_MAIN

#include <set>

#include "catch/catch.hpp"
#include "../card.hpp"
#include "../deck.hpp"
#include "../hand.hpp"
#include "../player.hpp"
#include "../game.hpp"

TEST_CASE("Test card class")
{
	Card* twelve = new Card(12);
	REQUIRE(twelve->GetValue() == 12);
	Card* one = new Card(1, twelve);
	Card* two = new Card(2, twelve, one);
	one->SetPrev(two);
	twelve->SetNext(two);
	REQUIRE(twelve->GetNext()->GetValue() == 2);
	REQUIRE(one->GetPrev()->GetValue() == 2);
	REQUIRE(twelve->GetNext()->GetPrev()->GetValue() == 12);
	REQUIRE(one->GetPrev()->GetNext()->GetValue() == 1);
}

TEST_CASE("Test deck basics")
{
	// create deck
	Deck deck;
	REQUIRE(deck.Peek() == -1);
	deck.Push(1);
	deck.Push(2);
	deck.Push(3);
	deck.Push(4);
	deck.Push(5);
	deck.Push(6);
	Card* six = deck.Draw();
	REQUIRE(six->GetValue() == 6);
	REQUIRE(six->GetNext() == nullptr);
	REQUIRE(six->GetPrev() == nullptr);

	REQUIRE(deck.Peek() == 5);

	deck.Discard(six);
	REQUIRE(deck.Peek() == 6);
}

TEST_CASE("Test full deck")
{
	Deck deck;
	deck.MakeFullDeck();

	//check for fullDeck	
	std::set<int> seen;
	bool correctCards = true;
	int numberOfCards = 0;
	Card* nextCard = deck.Draw();
	while(nextCard != nullptr)
	{
		numberOfCards++;
		int cardValue = nextCard->GetValue();
		if((cardValue < 1) || (cardValue > 60) || !seen.insert(cardValue).second)
		{
			correctCards = false;
			break;
		}
		nextCard = deck.Draw();
	}
	REQUIRE((correctCards && (numberOfCards == 60)));
}

TEST_CASE("Test shuffling")
{
	Deck unshuffledDeck;
	Deck shuffledDeck;
	unshuffledDeck.MakeFullDeck();
	shuffledDeck.MakeFullDeck();
	shuffledDeck.Shuffle();

	bool deckShuffled = false;

	Card* fromUnshuffled;
	Card* fromShuffled;
	for(int comparisonIndex = 0; comparisonIndex < 60; comparisonIndex++)
	{
		fromUnshuffled = unshuffledDeck.Draw();
		fromShuffled = shuffledDeck.Draw();
		if(fromUnshuffled->GetValue() != fromShuffled->GetValue())
		{
			deckShuffled = true;
			break;
		}	
	}
	REQUIRE(deckShuffled);
}

TEST_CASE("Testing user hand functions")
{
	Hand myHand;

	for (int i = 10; i > 0; --i)
	{
		myHand.AddToHand(new Card(i));
	}

	REQUIRE(myHand.HasRacko());

	Card* twenty = new Card(20);
	Card* two = myHand.SwapOutCard(twenty, 2);
	REQUIRE(!myHand.HasRacko());
	REQUIRE(two->GetValue() == 2);

	Card* foo = myHand.SwapOutCard(two, 1);
	REQUIRE(foo->GetValue() == 1);
	Card* bar = myHand.SwapOutCard(twenty, 10);
	REQUIRE(bar->GetValue() == 10);
}

TEST_CASE("Player")
{
	Hand paw;
	for (int i = 10; i > 0; --i)
	{
		 paw.AddToHand(new Card(i));
	}

	Player player1("Snuka", paw);
	REQUIRE(player1.GetName() == "Snuka");
	REQUIRE(player1.IsComputer() == false);

	REQUIRE(player1.ShowHand() == "1: 1\n2:  2\n3:   3\n4:    4\n5:     5\n6:      6\n7:       7\n8:        8\n9:         9\n10:          10\n");

	std::string turnPrompt = player1.TurnPrompt();
	REQUIRE("Snuka's turn" == turnPrompt);
	
	Card* discard = new Card(20);
	player1.SwapOutCard(discard, 3);
	REQUIRE(player1.ShowHand() == "1: 1\n2:  2\n3:                    20\n4:    4\n5:     5\n6:      6\n7:       7\n8:        8\n9:         9\n10:          10\n");

	// Create empty player and add details
	Player player2;
	player2.SetName("Sophie");
	player2.SetHand(paw);
}

TEST_CASE("Game basics")
{
	// create game with 2 players
	std::vector<Player> players;
	Player player1;
	player1.SetName("Snuka");
	player1.SetIsComputer(true);
	players.push_back(player1);
	Player player2;
	player2.SetName("Sophie");
	player2.SetIsComputer(true);
	players.push_back(player2);

	Game game(players);

	// test show hand
	REQUIRE(game.GetPlayer(1)->ShowHand() != "");
	REQUIRE(game.GetPlayer(2)->ShowHand() != "");

	// test show discard value
	REQUIRE(game.ShowTopOfDiscardPile() > 0);

	// make sure that an empty deck refills by shuffling the discard pile
	for (int i = 0; i < 60; ++i)
	{
		Card* card = game.DrawFromDeck();
		game.Discard(card);
	}

	game.DoNextTurn(); // Quick check to ensure that simple runtime errors don't exist
	REQUIRE(!game.IsGameOver());

	Hand winningHand;

	for (int i = 10; i > 0; --i)
	{
		winningHand.AddToHand(new Card(i));
	}

	game.GetPlayer(2)->SetHand(winningHand);

	game.DoNextTurn();
	REQUIRE(game.IsGameOver());
}

TEST_CASE("Test computer decision")
{
	Hand hand;

	for (int i = 10; i > 0; --i)
	{
		if (i == 5)
		{
			hand.AddToHand(new Card(3));
		}
		else
		{
			hand.AddToHand(new Card((i) * 6));
		}
	}

	bool isComputer = true;
	Player player1("Snuka", hand, isComputer);
	REQUIRE(player1.IsComputer() == true);

	REQUIRE(player1.MakeChoice(31) == "p"); // discard pile is good card
	REQUIRE(player1.MakeChoice(10) == "d"); // pile was bad, draw from the deck
	REQUIRE(player1.MakeChoice(1) == "p"); // discard pile is good card
	REQUIRE(player1.MakeChoice(60) == "p"); // discard pile is good card
	REQUIRE(player1.HasRacko() == false); // discard pile is good card
}

// Compile & run:
// make clean test
