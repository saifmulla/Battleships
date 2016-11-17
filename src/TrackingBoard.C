#include "Battleships/TrackingBoard.H"

Battleships::TrackingBoard::TrackingBoard()
:grid_(0)
{
	// define sizes to grid
	// initialise the array to all -1
	grid_.resize(X_SIZE);
	for(auto row = grid_.begin();row!=grid_.end();++row)
		row->resize(Y_SIZE);
}

void Battleships::TrackingBoard::display()
{

}

void Battleships::TrackingBoard::initialise()
{
	for(auto row = grid_.begin(); row!=grid_.end();++row)
		for(auto col = row->begin(); col!=row->end();++col)
			*col = -1;

}

std::vector<std::vector<int>>& Battleships::TrackingBoard::getBoard()
{
	return this->grid_;
}