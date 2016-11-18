#include "Battleships/PrimaryBoard.H"
#include <iostream>
Battleships::PrimaryBoard::PrimaryBoard()
:grid_(0)
{
	// define sizes to grid
	// initialise the array to all zeros
	grid_.resize(X_SIZE);
	for(auto row = grid_.begin();row!=grid_.end();++row)
		row->resize(Y_SIZE);
}

void Battleships::PrimaryBoard::display()
{
	std::cout << "====================" << std::endl;
	std::cout << "     Primary Board" << std::endl;
	std::cout << "====================" << std::endl;
	for(auto x:grid_){
		for(auto y:x){
			std::cout << y << "  ";		
		}
		std::cout << "\n\n";
	}
}

void Battleships::PrimaryBoard::initialise()
{
	// TODO: flip the arrangements to create diferences in placements
	// none of the ships placed will be touching any corners of grid
	// meaning all boundary squares will always be 0
	int r = rand() % 2;// randomly generate 0 or 1
	// first initialise the largest ship with 5 squares
	// zero we lay large ship vertically or horizontally
	// large ship will always be placed in center of grid
	constexpr const int half = 5;
	int i = 1;
	while(i<=5){
		grid_[i][4] = static_cast<int>(Ships::Five);
		++i;
	}

	constexpr const int endgrid = 10 - 2;
	// now place ship with 4 squares
	i = 5;
	while(i<=8){
		grid_[endgrid][i] = static_cast<int>(Ships::Four);
		++i;
	}

	// now place ship with 3 squares
	i = 3;
	while(i<=5){
		grid_[i][1] = grid_[i][endgrid] = static_cast<int>(Ships::Three);
		++i;
	}

	// now place ship with 2 squares
	i = 4;
	while(i<=5){
		grid_[i][2] = static_cast<int>(Ships::Two);
		++i;
	}

}

void Battleships::PrimaryBoard::setCell(int x, int y, int value)
{
	// this->grid_[x][y] = value;

}

const int Battleships::PrimaryBoard::getCell(int x, int y) const
{
	return this->grid_[x][y];
}

// TODO: replace this with optimal shared_ptr<>
std::vector<std::vector<int>>& Battleships::PrimaryBoard::getBoard()
{
	return this->grid_;
}

// std::shared_ptr<std::vector<std::vector<int>>>
// Battleships::PrimaryBoard::getBoard()
// {
// 	// return grid_;
// }
