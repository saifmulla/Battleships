#ifndef BATTLESHIPS_PRIMARYBOARD_H
#define BATTLESHIPS_PRIMARYBOARD_H

#include "Battleships/Board.H"

#include <cstdlib>
#include <vector>
#include <array>

namespace Battleships {

class EXPORTS PrimaryBoard : public Board {

private:
	std::vector<std::vector<int>> grid_;
	int shipLength_5 = 1;
	int shipLength_4 = 1;
	int shipLength_3 = 2;
	int shipLength_2 = 1;
	std::array<int,5> ships = std::array<int,5>{5, 4, 3, 2, 3};

public:
	PrimaryBoard();

	virtual void display() override;

	virtual void initialise() override;

	// virtual std::shared_ptr<std::vector<std::vector<int>>> getBoard() override;

	virtual std::vector<std::vector<int>>& getBoard() override;

};	

}// end namespace

#endif