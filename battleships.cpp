// this is the main executable file with executable code

#include "battleships/battleships.H"
#include <iostream>
#include <string>
#include <array>

using namespace Battleships;

int main(int argc, char *argv[])
{
	std::string player1 = "";
	std::string player2 = "";

	std::cout << "Enter name of first player: ";
	std::cin >> player1;

	std::cout << "Enter name of second player: ";
	std::cin >> player2;

	std::array<std::string,2> players = {player1,player2};
	// 1. initialise game
	Game* game = new BattleShips(player1,player2);

	//2. intialise game
	game->initialise();

	//3. validate all data
	game->validate();

	// TODO 4. run a loop and for every turn ask for grid to fire
	game->play();
	
	return 1;
}
