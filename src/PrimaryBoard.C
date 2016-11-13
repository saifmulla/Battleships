#include "Battleships/PrimaryBoard.H"

Battleships::PrimaryBoard::PrimaryBoard()
{
	// initialise the array to all zeros

	for(int i = 0; i < X_SIZE; ++i){
		for(int j = 0; j < Y_SIZE; ++j){
			grid[i][j] = 0;
		}
	}
}

void Battleships::PrimaryBoard::display()
{

}

void Battleships::PrimaryBoard::initialise()
{
	int randIndex = rand() % 10; // get a index to start 
	

}