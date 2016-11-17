#ifndef BATTLESHIPS_VALIDATOR_H
#define BATTLESHIPS_VALIDATOR_H

#include "Battleships/Exports.H"
#include <vector>
#include <cstdlib>
#include <iostream>

namespace Battleships {

	class EXPORTS Validator {
	// private:

	public:
		// default constructor
		Validator();

		// checkPrimaryBoard
		// use this function to validate primary board created for a player
		// essentially it validates all the requirements of a primary board
		// 1. checking for 17 full squares/cells in the matrix
		// 2. ensuring there is no overlapping amongst placed ships
		bool checkPrimaryBoard(const std::vector<std::vector<int>>& primaryBoard);

		// getWinner
		// use this function to check if the tracking board contains 17 squares 
		// for matching primary grid, basically here were are checking the 
		// existence of 1's on the grid, 1 represents a full square on primary grid
		bool getWinner(const std::vector<std::vector<int>>& trackingBoard);

		// displayBoard
		// display the board and its contents in a more representable form
		// that could be understood by user
		// this functiona can be used to display any type of board such as
		// primary or tracking board
		void displayBoard(std::vector<std::vector<int>>& board);

	}; // end class
}// end namespace
#endif /* end BATTLESHIPS_VALIDATOR_H */