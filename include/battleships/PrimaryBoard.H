#ifndef BATTLESHIPS_PRIMARYBOARD_H
#define BATTLESHIPS_PRIMARYBOARD_H

#include "Battleships/Board.H"

#include <cstdlib>
#include <array>

namespace Battleships {

class EXPORTS PrimaryBoard : Board {

private:
	int shipLength_5 = 1;
	int shipLength_4 = 1;
	int shipLength_3 = 2;
	int shipLength_2 = 1;
	std::array<int,5> ships = {5,4,3,2,3};

public:
	PrimaryBoard();

	virtual void display() override;

	virtual void initialise() override;

};	

}// end namespace

#endif