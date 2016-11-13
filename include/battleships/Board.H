#ifndef BATTLESHIPS_BOARD_H
#define BATTLESHIPS_BOARD_H

#include "battleships/Exports.H"
#include <array>

namespace Battleships {

class EXPORTS Board {

protected:
	std::array<std::array<int,X_SIZE>, Y_SIZE> grid;

public:
	virtual void display() = 0;

	virtual void initialise() = 0;

}; //end class Board

}// end namespace BattleShips
#endif