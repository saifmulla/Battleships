#ifndef BATTLESHIPS_BOARD_H
#define BATTLESHIPS_BOARD_H

#include "battleships/Exports.H"
#include <memory>
#include <vector>

namespace Battleships {

class EXPORTS Board {

protected:
	enum class Ships : int {
		One = 1, // ship with 1 squares
		Two, // ship with 2 squares
		Three, // ship with 3 squares
		Four, // ship with 4 squares
		Five //ship with 5 squares
	};

public:
	virtual void display() = 0;

	virtual void initialise() = 0;

	// virtual std::shared_ptr<std::vector<std::vector<int>>>
	// getBoard() = 0;

	virtual std::vector<std::vector<int>>& getBoard() = 0;

	virtual ~Board(){
	}

}; //end class Board

}// end namespace BattleShips
#endif