#ifndef BATTLESHIPS_BattleShips_H
#define BATTLESHIPS_BattleShips_H

#include "battleships/Game.H"
#include <string>
#include <vector>

// BattleShips
//
// This game is Battleships from class Game, it is a subclass of type Game.
// it allows to create two player battleship game and which keeps track of 
// battleships being destroyed by each player

namespace Battleships {

class Validator;//forward declaring validator class
class PrimaryBoard;// forward declaring class PrimaryBoard
class TrackingBoard;// forward declaring class SecondaryBoard

class EXPORTS BattleShips : public Game
{

private:
	std::vector<Battleships::PrimaryBoard*> primaryBoards_;
	std::vector<Battleships::TrackingBoard*> trackingBoards_;
	Battleships::Validator* valid_;
	std::string player1_;
	std::string player2_;
	enum class Player : int{
		one = 0,
		two
	};

public:
	// this constructor is explicit
	explicit BattleShips(
		const std::string player1,
		const std::string player2
		);

	virtual void initialise() override;

	virtual void validate() override;

	virtual void play() override;

	virtual bool getResult() override;

	const std::string& getPlayer1() const;

	const std::string& getPlayer2() const;

};

}// end namspace
#endif