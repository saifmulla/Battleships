#include "battleships/BattleShips.H"

void Battleships::BattleShips::initialise()
{
	// 1. create objects for tracking boards for both players
	// 2. create objects for primary boards for both players
	// 3. initialise primary boards for filling ship positions
	// 4. bind object of Validate class to valid
}

void Battleships::BattleShips::validate()
{
	// 1. validate primary boards to check if 17 boxes are full and 
	// ships appropriately positioned
	// 2. also validate if all the values of tracking boards are set to -1

}

void Battleships::BattleShips::play()
{
		
}

bool Battleships::BattleShips::getResult()
{
	return true;
}

////// constructor \\\\\\\\\\\\\\\//

Battleships::BattleShips::BattleShips(
	const std::string player1,
	const std::string player2
	)
:primaryBoards_(0),trackingBoards_(0),valid_(0),player1_(player1),player2_(player2)
{
	primaryBoards_.resize(2);
	trackingBoards_.resize(2);
}

const std::string& Battleships::BattleShips::getPlayer1() const {
	return this->player1_;
}

const std::string& Battleships::BattleShips::getPlayer2() const {
	return this->player2_;
}