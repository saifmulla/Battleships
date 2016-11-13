#include "Battleships/TrackingBoard.H"

Battleships::TrackingBoard::TrackingBoard()
{
	// initialise the array to all zeros
	for(int i = 0; i < X_SIZE; ++i){
		for(int j = 0; j < Y_SIZE; ++j){
			grid[i][j] = -1;
		}
	}
}

void Battleships::TrackingBoard::display()
{

}

void Battleships::TrackingBoard::initialise()
{

}