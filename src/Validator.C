#include "battleships/Validator.H"

// default constructor
Battleships::Validator::Validator()
{
}

// CheckPrimaryBoard
// @param vector<vector<int>> an 2d array of grid
// @return bool
// This function validates a primary board by checking for 17 full squares
// in this case full square means non zero cell of grid/Board
bool Battleships::Validator::checkPrimaryBoard(
	const std::vector<std::vector<int>>& primaryBoard
	)
{
	// this count the number full square basically looking for
	// sum of 61 from 17 non zero values
	int full = 0;
	for(auto x:primaryBoard){
		for(auto y:x){
			full += y;
		}
	}

	// if the sum is as expected return true else by default it always
	// returns false
	if(full == kTotalSumofNonZeros)
		return true;

	return false;
}

// GetWinner
// @param vector<vector<int>> an 2d array of grid
// @return bool
// This function will be used to check if there is a winner among two players
// such as if a player has destroyed all ships of his oponents
// basically we will be doing by checking the tracking board of the player to 
// conclude if player has targeted all the full squares on opponents primary 
// board. By default a tracking board is initialised with -1 we will looking
// to obtain all positive integers and calculate their sum which will be 
// equal to kTotalSumodNonZeros
bool Battleships::Validator::getWinner(
	const std::vector<std::vector<int>>& trackingBoard
	)
{
	int fullcounter = 0;
	for(auto r:trackingBoard){
		for(auto c:r){
			if(c>=0)
				fullcounter+=c;
		}
	}

	if(fullcounter == kTotalSumofNonZeros)
		return true;

	return false;
}

void Battleships::Validator::displayBoard(
	std::vector<std::vector<int>>& board
	)
{
	for(auto x:board){
		for(auto y:x){
			std::cout << y << "  ";		
		}
		std::cout << "\n\n";
	}
}
