// this is the main executable file with executable code

#include "battleships/battleships.H"
#include <iostream>
#include <string>

using namespace Battleships;

int main(int argc, char *argv[])
{
	std::string player1 = "";
	std::string player2 = "";

	std::cout << "Enter name of first player: ";
	std::cin >> player1;

	std::cout << "Enter name of second player: ";
	std::cin >> player2;

	// TODO 1. initialise battleships
	BattleShips* battle = new BattleShips(player1,player2);
	// TODO 2. intialise game

	// TODO 3. validate all data

	// TODO 4. run a loop and for every turn ask for grid to fire

	// pass the grid number

	return 1;
}
