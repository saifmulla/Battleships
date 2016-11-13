#ifndef BATTLESHIPS_TRACKINGBOARD_H
#define BATTLESHIPS_TRACKINGBOARD_H

#include "Battleships/Board.H"

namespace Battleships {

class EXPORTS TrackingBoard : public Board {
	
// private:
	// std::array<std::array<int,X_SIZE>, Y_SIZE> grid;

public:
	TrackingBoard();

	virtual void display() override;

	virtual void initialise() override;

};	

}// end namespace

#endif